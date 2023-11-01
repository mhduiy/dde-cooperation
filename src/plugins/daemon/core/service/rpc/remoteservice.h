﻿// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef REMOTE_SERVICE_H
#define REMOTE_SERVICE_H

#include <QObject>
#include <QReadWriteLock>
#include <QMap>

#include "message.pb.h"
#include "zrpc.h"

class RemoteServiceImpl : public RemoteService
{
public:
    RemoteServiceImpl() = default;
    virtual ~RemoteServiceImpl() = default;

    virtual void login(::google::protobuf::RpcController *controller,
                       const ::LoginRequest *request,
                       ::LoginResponse *response,
                       ::google::protobuf::Closure *done);

    virtual void query_peerinfo(::google::protobuf::RpcController *controller,
                                const ::PeerInfo *request,
                                ::PeerInfo *response,
                                ::google::protobuf::Closure *done);

    virtual void misc(::google::protobuf::RpcController *controller,
                      const ::JsonMessage *request,
                      ::JsonMessage *response,
                      ::google::protobuf::Closure *done);

    virtual void fsaction(::google::protobuf::RpcController *controller,
                          const ::FileAction *request,
                          ::FileResponse *response,
                          ::google::protobuf::Closure *done);

    virtual void filetrans_job(::google::protobuf::RpcController *controller,
                               const ::FileTransJob *request,
                               ::FileTransResponse *response,
                               ::google::protobuf::Closure *done);

    virtual void filetrans_create(::google::protobuf::RpcController *controller,
                                  const ::FileTransCreate *request,
                                  ::FileTransResponse *response,
                                  ::google::protobuf::Closure *done);

    virtual void filetrans_block(::google::protobuf::RpcController *controller,
                                 const ::FileTransBlock *request,
                                 ::FileTransResponse *response,
                                 ::google::protobuf::Closure *done);

    virtual void filetrans_update(::google::protobuf::RpcController *controller,
                                  const ::FileTransUpdate *request,
                                  ::FileTransResponse *response,
                                  ::google::protobuf::Closure *done);
    virtual void apply_trans_files(::google::protobuf::RpcController* controller,
                                   const ::ApplyTransFilesRequest* request,
                                   ::ApplyTransFilesResponse* response,
                                   ::google::protobuf::Closure* done);

private:
};

class ZRpcClientExecutor
{
public:
    ZRpcClientExecutor(const char *targetip, uint16_t port)
    {
        _client = new zrpc_ns::ZRpcClient(targetip, port, true);
    }

    ~ZRpcClientExecutor() = default;

    zrpc_ns::ZRpcChannel *chan() { return _client->getChannel(); }

    zrpc_ns::ZRpcController *control() { return _client->getControler(); }

    QString targetIP() { return _client->getControler()->LocalAddr()->getIP(); }

private:
    zrpc_ns::ZRpcClient *_client{ nullptr };
};

class RemoteServiceBinder : public QObject
{
    Q_OBJECT
public:
    explicit RemoteServiceBinder(QObject *parent = nullptr);
    ~RemoteServiceBinder();

    void startRpcListen(const char *keypath, const char *crtpath);

    void createExecutor(const QString &appname, const char *targetip, uint16_t port);

    void doLogin(const QString &appname, const char *username, const char *pincode);

    void doQuery(const QString &appname);

    //发到哪一个前端的自定义信息
    QString doMisc(const char *appname, const char *miscdata);

    // 通知远端准备执行作业：接收或发送。
    int doTransfileJob(const char *appname, int id, const char *jobpath, bool hidden, bool recursive, bool recv);

    // 发送文件数据信息。
    int doSendFileInfo(const QString &appname, int jobid, int fileid, const char *subdir, const char *filepath);

    // 发送文件数据块。
    int doSendFileBlock(const QString &appname, FileTransBlock fileblock);

    // 发送文件传输报告。
    int doUpdateTrans(const QString &appname, FileTransUpdate update);

    // 发送文件传输请求
    void doSendApplyTransFiles(ApplyTransFilesRequest applyInfo);

signals:
    void loginResult(bool result, QString who);
    void queryResult(bool result, QString msg);
    void miscResult(bool result, QString msg);
    void fileActionResult(bool result, int id);

    void fileTransResult(const char *path, int id, bool result);
    void fileTransSpeed(const char *path, int id, size_t speed);

public slots:

private:
    QSharedPointer<ZRpcClientExecutor> executor(const QString &appname);

private:
    QReadWriteLock _executor_lock;
    QMap<QString, QSharedPointer<ZRpcClientExecutor>>_executor_ps;

};

#endif   // REMOTE_SERVICE_H
