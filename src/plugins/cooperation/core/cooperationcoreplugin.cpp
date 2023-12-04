// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "cooperationcoreplugin.h"
#include "base/baseutils.h"
#include "common/commonutils.h"
#include "events/cooperationcoreeventreceiver.h"
#include "utils/cooperationutil.h"
#include "maincontroller/maincontroller.h"
#include "transfer/transferhelper.h"
#include "cooperation/cooperationmanager.h"
#include "config/configmanager.h"
#include "singleton/singleapplication.h"

#ifdef WIN32
#include "proxy/cooperationproxy.h"
#endif

#include <co/flag.h>
#include <co/log.h>

using namespace cooperation_core;
using namespace deepin_cross;

void CooperaionCorePlugin::initialize()
{
    if (qApp->property("onlyTransfer").toBool()) {
        auto appName = qApp->applicationName();
        qApp->setApplicationName(MainAppName);
        ConfigManager::instance();
        qApp->setApplicationName(appName);
    } else {
        connect(qApp, &SingleApplication::raiseWindow, this, [] { CooperationUtil::instance()->mainWindow()->activateWindow(); });
    }

    CooperationUtil::instance();
    bindEvents();
    initLog();

    CommonUitls::loadTranslator();
}

bool CooperaionCorePlugin::start()
{
    CooperationUtil::instance()->mainWindow()->show();
    MainController::instance()->regist();
    TransferHelper::instance()->regist();
    CooperationManager::instance()->regist();
    MainController::instance()->start();

#ifdef WIN32
    CooperationProxy::instance();
#endif

    return true;
}

void CooperaionCorePlugin::stop()
{
    CooperationUtil::instance()->destroyMainWindow();
    MainController::instance()->unregist();
    MainController::instance()->stop();
}

void CooperaionCorePlugin::bindEvents()
{
    dpfSlotChannel->connect("cooperation_core", "slot_Register_Operation",
                            CooperationCoreEventReceiver::instance(), &CooperationCoreEventReceiver::handleRegisterOperation);
}

void CooperaionCorePlugin::initLog()
{
    flag::set_value("rpc_log", "false");   //rpc日志关闭
    flag::set_value("cout", "true");   //终端日志输出
    flag::set_value("journal", "true");   //journal日志

    fastring logdir = deepin_cross::BaseUtils::logDir().toStdString();
    LOG << "set logdir: " << logdir.c_str();
    flag::set_value("log_dir", logdir);   //日志保存目录
}
