// Autogenerated.
// DO NOT EDIT. All changes will be undone.
#pragma once

#include "co/json.h"

struct SendResult {
    uint32 protocolType;
    int32 errorType;
    fastring data;

    void from_json(const co::Json& _x_) {
        protocolType = (uint32)_x_.get("protocolType").as_int64();
        errorType = (int32)_x_.get("errorType").as_int64();
        data = _x_.get("data").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("protocolType", protocolType);
        _x_.add_member("errorType", errorType);
        _x_.add_member("data", data);
        return _x_;
    }
};

struct UserLoginInfo {
    fastring name;
    fastring auth;
    fastring my_uid;
    fastring my_name;
    fastring session_id;
    fastring selfappName;
    fastring appName;
    fastring version;
    fastring ip;

    void from_json(const co::Json& _x_) {
        name = _x_.get("name").as_c_str();
        auth = _x_.get("auth").as_c_str();
        my_uid = _x_.get("my_uid").as_c_str();
        my_name = _x_.get("my_name").as_c_str();
        session_id = _x_.get("session_id").as_c_str();
        selfappName = _x_.get("selfappName").as_c_str();
        appName = _x_.get("appName").as_c_str();
        version = _x_.get("version").as_c_str();
        ip = _x_.get("ip").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("name", name);
        _x_.add_member("auth", auth);
        _x_.add_member("my_uid", my_uid);
        _x_.add_member("my_name", my_name);
        _x_.add_member("session_id", session_id);
        _x_.add_member("selfappName", selfappName);
        _x_.add_member("appName", appName);
        _x_.add_member("version", version);
        _x_.add_member("ip", ip);
        return _x_;
    }
};

struct PeerInfo {
    fastring username;
    fastring hostname;
    fastring platform;
    fastring version;
    bool privacy_mode;

    void from_json(const co::Json& _x_) {
        username = _x_.get("username").as_c_str();
        hostname = _x_.get("hostname").as_c_str();
        platform = _x_.get("platform").as_c_str();
        version = _x_.get("version").as_c_str();
        privacy_mode = _x_.get("privacy_mode").as_bool();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("username", username);
        _x_.add_member("hostname", hostname);
        _x_.add_member("platform", platform);
        _x_.add_member("version", version);
        _x_.add_member("privacy_mode", privacy_mode);
        return _x_;
    }
};

struct UserLoginResultInfo {
    PeerInfo peer;
    fastring token;
    fastring appName;
    bool result;

    void from_json(const co::Json& _x_) {
        peer.from_json(_x_.get("peer"));
        token = _x_.get("token").as_c_str();
        appName = _x_.get("appName").as_c_str();
        result = _x_.get("result").as_bool();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("peer", peer.as_json());
        _x_.add_member("token", token);
        _x_.add_member("appName", appName);
        _x_.add_member("result", result);
        return _x_;
    }
};

struct MiscInfo {
    fastring appName;
    fastring json;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        json = _x_.get("json").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("json", json);
        return _x_;
    }
};

struct FileTransJob {
    int32 job_id;
    fastring path;
    fastring save_path;
    bool include_hidden;
    bool sub;
    bool write;
    fastring app_who;
    fastring targetAppname;
    fastring ip;

    void from_json(const co::Json& _x_) {
        job_id = (int32)_x_.get("job_id").as_int64();
        path = _x_.get("path").as_c_str();
        save_path = _x_.get("save_path").as_c_str();
        include_hidden = _x_.get("include_hidden").as_bool();
        sub = _x_.get("sub").as_bool();
        write = _x_.get("write").as_bool();
        app_who = _x_.get("app_who").as_c_str();
        targetAppname = _x_.get("targetAppname").as_c_str();
        ip = _x_.get("ip").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("job_id", job_id);
        _x_.add_member("path", path);
        _x_.add_member("save_path", save_path);
        _x_.add_member("include_hidden", include_hidden);
        _x_.add_member("sub", sub);
        _x_.add_member("write", write);
        _x_.add_member("app_who", app_who);
        _x_.add_member("targetAppname", targetAppname);
        _x_.add_member("ip", ip);
        return _x_;
    }
};

struct FileEntry {
    int32 filetype;
    fastring name;
    bool hidden;
    int64 size;
    int64 modified_time;
    fastring appName;
    fastring rcvappName;

    void from_json(const co::Json& _x_) {
        filetype = (int32)_x_.get("filetype").as_int64();
        name = _x_.get("name").as_c_str();
        hidden = _x_.get("hidden").as_bool();
        size = (int64)_x_.get("size").as_int64();
        modified_time = (int64)_x_.get("modified_time").as_int64();
        appName = _x_.get("appName").as_c_str();
        rcvappName = _x_.get("rcvappName").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("filetype", filetype);
        _x_.add_member("name", name);
        _x_.add_member("hidden", hidden);
        _x_.add_member("size", size);
        _x_.add_member("modified_time", modified_time);
        _x_.add_member("appName", appName);
        _x_.add_member("rcvappName", rcvappName);
        return _x_;
    }
};

struct FileTransCreate {
    int32 job_id;
    int32 file_id;
    fastring sub_dir;
    FileEntry entry;

    void from_json(const co::Json& _x_) {
        job_id = (int32)_x_.get("job_id").as_int64();
        file_id = (int32)_x_.get("file_id").as_int64();
        sub_dir = _x_.get("sub_dir").as_c_str();
        entry.from_json(_x_.get("entry"));
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("job_id", job_id);
        _x_.add_member("file_id", file_id);
        _x_.add_member("sub_dir", sub_dir);
        _x_.add_member("entry", entry.as_json());
        return _x_;
    }
};

struct FileTransResponse {
    int32 id;
    fastring name;
    int32 result;

    void from_json(const co::Json& _x_) {
        id = (int32)_x_.get("id").as_int64();
        name = _x_.get("name").as_c_str();
        result = (int32)_x_.get("result").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("id", id);
        _x_.add_member("name", name);
        _x_.add_member("result", result);
        return _x_;
    }
};

struct FileTransBlock {
    int32 job_id;
    int32 file_id;
    fastring rootdir;
    fastring filename;
    uint32 blk_id;
    int32 flags;
    int64 data_size{0};

    void from_json(const co::Json& _x_) {
        job_id = (int32)_x_.get("job_id").as_int64();
        file_id = (int32)_x_.get("file_id").as_int64();
        rootdir = _x_.get("rootdir").as_c_str();
        filename = _x_.get("filename").as_c_str();
        blk_id = (uint32)_x_.get("blk_id").as_int64();
        flags = (int32)_x_.get("flags").as_int64();
        data_size = _x_.get("data_size").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("job_id", job_id);
        _x_.add_member("file_id", file_id);
        _x_.add_member("rootdir", rootdir);
        _x_.add_member("filename", filename);
        _x_.add_member("blk_id", blk_id);
        _x_.add_member("flags", flags);
        _x_.add_member("data_size", data_size);
        return _x_;
    }
};

struct FileTransJobAction {
    int32 job_id;
    fastring appname;
    uint32 type;

    void from_json(const co::Json& _x_) {
        job_id = (int32)_x_.get("job_id").as_int64();
        appname = _x_.get("appname").as_c_str();
        type = (uint32)_x_.get("type").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("job_id", job_id);
        _x_.add_member("appname", appname);
        _x_.add_member("type", type);
        return _x_;
    }
};

struct FileTransJobReport {
    int32 job_id;
    fastring path;
    fastring error;
    int32 result;

    void from_json(const co::Json& _x_) {
        job_id = (int32)_x_.get("job_id").as_int64();
        path = _x_.get("path").as_c_str();
        error = _x_.get("error").as_c_str();
        result = (int32)_x_.get("result").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("job_id", job_id);
        _x_.add_member("path", path);
        _x_.add_member("error", error);
        _x_.add_member("result", result);
        return _x_;
    }
};

struct ShareEvents {
    uint32 eventType;
    fastring data;

    void from_json(const co::Json& _x_) {
        eventType = (uint32)_x_.get("eventType").as_int64();
        data = _x_.get("data").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("eventType", eventType);
        _x_.add_member("data", data);
        return _x_;
    }
};

struct ShareConnectApply {
    fastring appName;
    fastring tarAppname;
    fastring ip;
    fastring tarIp;
    fastring data;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        ip = _x_.get("ip").as_c_str();
        tarIp = _x_.get("tarIp").as_c_str();
        data = _x_.get("data").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("ip", ip);
        _x_.add_member("tarIp", tarIp);
        _x_.add_member("data", data);
        return _x_;
    }
};

struct ShareDisConnect {
    fastring appName;
    fastring tarAppname;
    fastring msg;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        msg = _x_.get("msg").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("msg", msg);
        return _x_;
    }
};

struct ShareConnectReply {
    fastring appName;
    fastring tarAppname;
    fastring msg;
    fastring ip;
    int32 reply;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        msg = _x_.get("msg").as_c_str();
        ip = _x_.get("ip").as_c_str();
        reply = (int32)_x_.get("reply").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("msg", msg);
        _x_.add_member("ip", ip);
        _x_.add_member("reply", reply);
        return _x_;
    }
};

struct ShareStop {
    fastring appName;
    fastring tarAppname;
    int32 flags{ 0 };

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        flags = (int32)_x_.get("flags").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("flags", flags);
        return _x_;
    }
};

struct ShareServerConfig {
    fastring server_screen{ "" };
    fastring client_screen{ "" };
    fastring screen_left{ "" };
    fastring screen_right{ "" };
    bool left_halfDuplexCapsLock{ false };
    bool left_halfDuplexNumLock{ false };
    bool left_halfDuplexScrollLock{ false };
    bool left_xtestIsXineramaUnaware{ false };
    bool left_preserveFocus{ false };
    fastring left_switchCorners{ "none" };
    int32 left_switchCornerSize{ 0 };
    bool right_halfDuplexCapsLock{ false };
    bool right_halfDuplexNumLock{ false };
    bool right_halfDuplexScrollLock{ false };
    bool right_xtestIsXineramaUnaware{ false };
    bool right_preserveFocus{ false };
    fastring right_switchCorners{ "none" };
    int32 right_switchCornerSize{ 0 };
    bool relativeMouseMoves{ false };
    bool screenSaverSync{ true };
    bool win32KeepForeground{ false };
    bool clipboardSharing{ false };
    fastring switchCorners{ "none" };
    int32 switchCornerSize{ 0 };

    void from_json(const co::Json& _x_) {
        server_screen = _x_.get("server_screen").as_c_str();
        client_screen = _x_.get("client_screen").as_c_str();
        screen_left = _x_.get("screen_left").as_c_str();
        screen_right = _x_.get("screen_right").as_c_str();
        left_halfDuplexCapsLock = _x_.get("left_halfDuplexCapsLock").as_bool();
        left_halfDuplexNumLock = _x_.get("left_halfDuplexNumLock").as_bool();
        left_halfDuplexScrollLock = _x_.get("left_halfDuplexScrollLock").as_bool();
        left_xtestIsXineramaUnaware = _x_.get("left_xtestIsXineramaUnaware").as_bool();
        left_preserveFocus = _x_.get("left_preserveFocus").as_bool();
        left_switchCorners = _x_.get("left_switchCorners").as_c_str();
        left_switchCornerSize = (int32)_x_.get("left_switchCornerSize").as_int64();
        right_halfDuplexCapsLock = _x_.get("right_halfDuplexCapsLock").as_bool();
        right_halfDuplexNumLock = _x_.get("right_halfDuplexNumLock").as_bool();
        right_halfDuplexScrollLock = _x_.get("right_halfDuplexScrollLock").as_bool();
        right_xtestIsXineramaUnaware = _x_.get("right_xtestIsXineramaUnaware").as_bool();
        right_preserveFocus = _x_.get("right_preserveFocus").as_bool();
        right_switchCorners = _x_.get("right_switchCorners").as_c_str();
        right_switchCornerSize = (int32)_x_.get("right_switchCornerSize").as_int64();
        relativeMouseMoves = _x_.get("relativeMouseMoves").as_bool();
        screenSaverSync = _x_.get("screenSaverSync").as_bool();
        win32KeepForeground = _x_.get("win32KeepForeground").as_bool();
        clipboardSharing = _x_.get("clipboardSharing").as_bool();
        switchCorners = _x_.get("switchCorners").as_c_str();
        switchCornerSize = (int32)_x_.get("switchCornerSize").as_int64();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("server_screen", server_screen);
        _x_.add_member("client_screen", client_screen);
        _x_.add_member("screen_left", screen_left);
        _x_.add_member("screen_right", screen_right);
        _x_.add_member("left_halfDuplexCapsLock", left_halfDuplexCapsLock);
        _x_.add_member("left_halfDuplexNumLock", left_halfDuplexNumLock);
        _x_.add_member("left_halfDuplexScrollLock", left_halfDuplexScrollLock);
        _x_.add_member("left_xtestIsXineramaUnaware", left_xtestIsXineramaUnaware);
        _x_.add_member("left_preserveFocus", left_preserveFocus);
        _x_.add_member("left_switchCorners", left_switchCorners);
        _x_.add_member("left_switchCornerSize", left_switchCornerSize);
        _x_.add_member("right_halfDuplexCapsLock", right_halfDuplexCapsLock);
        _x_.add_member("right_halfDuplexNumLock", right_halfDuplexNumLock);
        _x_.add_member("right_halfDuplexScrollLock", right_halfDuplexScrollLock);
        _x_.add_member("right_xtestIsXineramaUnaware", right_xtestIsXineramaUnaware);
        _x_.add_member("right_preserveFocus", right_preserveFocus);
        _x_.add_member("right_switchCorners", right_switchCorners);
        _x_.add_member("right_switchCornerSize", right_switchCornerSize);
        _x_.add_member("relativeMouseMoves", relativeMouseMoves);
        _x_.add_member("screenSaverSync", screenSaverSync);
        _x_.add_member("win32KeepForeground", win32KeepForeground);
        _x_.add_member("clipboardSharing", clipboardSharing);
        _x_.add_member("switchCorners", switchCorners);
        _x_.add_member("switchCornerSize", switchCornerSize);
        return _x_;
    }
};

struct ShareStart {
    fastring appName{""};
    fastring tarAppname{""};
    ShareServerConfig config;
    fastring ip{""};
    int32 port{ 0 };

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        config.from_json(_x_.get("config"));
        ip = _x_.get("ip").as_c_str();
        port = static_cast<int32>(_x_.get("port").as_int64());
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("config", config.as_json());
        _x_.add_member("ip", ip);
        _x_.add_member("port", port);
        return _x_;
    }
};

struct ShareStartReply {
    bool result;
    bool isRemote;
    fastring errorMsg;

    void from_json(const co::Json& _x_) {
        result = _x_.get("result").as_bool();
        isRemote = _x_.get("isRemote").as_bool();
        errorMsg = _x_.get("errorMsg").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("result", result);
        _x_.add_member("isRemote", isRemote);
        _x_.add_member("errorMsg", errorMsg);
        return _x_;
    }
};

struct ShareStartRmoteReply {
    bool result;
    fastring appName;
    fastring tarAppname;
    fastring errorMsg;

    void from_json(const co::Json& _x_) {
        result = _x_.get("result").as_bool();
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        errorMsg = _x_.get("errorMsg").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("result", result);
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("errorMsg", errorMsg);
        return _x_;
    }
};

// 取消共享连接申请
struct ShareConnectDisApply {
    fastring appName;
    fastring tarAppname;
    fastring ip;
    fastring msg;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        ip = _x_.get("ip").as_c_str();
        msg = _x_.get("msg").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("ip", ip);
        _x_.add_member("msg", msg);
        return _x_;
    }
};

// PingPong请求响应结构
struct PingPong {
    fastring appName;
    fastring tarAppname;
    fastring ip;

    void from_json(const co::Json& _x_) {
        appName = _x_.get("appName").as_c_str();
        tarAppname = _x_.get("tarAppname").as_c_str();
        ip = _x_.get("ip").as_c_str();
    }

    co::Json as_json() const {
        co::Json _x_;
        _x_.add_member("appName", appName);
        _x_.add_member("tarAppname", tarAppname);
        _x_.add_member("ip", ip);
        return _x_;
    }
};

