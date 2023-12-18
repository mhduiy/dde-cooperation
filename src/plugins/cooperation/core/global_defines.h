﻿#ifndef TYPE_DEFINES_H
#define TYPE_DEFINES_H

#ifdef _WIN32
#include <QMainWindow>
#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
typedef QMainWindow CooperationMainWindow;
typedef QDialog CooperationDialog;
typedef QToolButton CooperationIconButton;
typedef QDialog CooperationAbstractDialog;
typedef QPushButton CooperationSuggestButton;
typedef QCheckBox CooperationSwitchButton;
typedef QToolButton CooperationFloatingEdit;
typedef QLabel CooperationSpinner;
typedef QLineEdit CooperationLineEdit;
typedef QLabel CooperationLabel;
#else
#include <DMainWindow>
#include <DAbstractDialog>
#include <DSwitchButton>
#include <DSuggestButton>
#include <DSearchEdit>
#include <DDialog>
#include <DSpinner>
#include <DIconButton>
#include <DFloatingButton>
#include <DLineEdit>
#include <DLabel>
typedef DTK_WIDGET_NAMESPACE::DDialog CooperationDialog;
typedef DTK_WIDGET_NAMESPACE::DSpinner CooperationSpinner;
typedef DTK_WIDGET_NAMESPACE::DMainWindow CooperationMainWindow;
typedef DTK_WIDGET_NAMESPACE::DAbstractDialog CooperationAbstractDialog;
typedef DTK_WIDGET_NAMESPACE::DSwitchButton CooperationSwitchButton;
typedef DTK_WIDGET_NAMESPACE::DSuggestButton CooperationSuggestButton;
typedef DTK_WIDGET_NAMESPACE::DSearchEdit CooperationSearchEdit;
typedef DTK_WIDGET_NAMESPACE::DIconButton CooperationIconButton;
typedef DTK_WIDGET_NAMESPACE::DFloatingButton CooperationFloatingEdit;
typedef DTK_WIDGET_NAMESPACE::DLineEdit CooperationLineEdit;
typedef DTK_WIDGET_NAMESPACE::DLabel CooperationLabel;
#endif

namespace OperationKey {
inline constexpr char kID[] { "id" };
inline constexpr char kIconName[] { "icon-name" };
inline constexpr char kButtonStyle[] { "button-style" };
inline constexpr char kLocation[] { "location" };
inline constexpr char kDescription[] { "description" };
inline constexpr char kClickedCallback[] { "clicked-callback" };
inline constexpr char kVisibleCallback[] { "visible-callback" };
inline constexpr char kClickableCallback[] { "clickable-callback" };
}

namespace AppSettings {
inline constexpr char GenericGroup[] { "GenericAttribute" };
inline constexpr char DeviceNameKey[] { "DeviceName" };
inline constexpr char DiscoveryModeKey[] { "DiscoveryMode" };
inline constexpr char PeripheralShareKey[] { "PeripheralShare" };
inline constexpr char LinkDirectionKey[] { "LinkDirection" };
inline constexpr char TransferModeKey[] { "TransferMode" };
inline constexpr char StoragePathKey[] { "StoragePath" };
inline constexpr char ClipboardShareKey[] { "ClipboardShare" };
inline constexpr char CooperationEnabled[] { "CooperationEnabled" };

inline constexpr char CacheGroup[] { "Cache" };
inline constexpr char TransHistoryKey[] { "TransHistory" };
inline constexpr char ConnectHistoryKey[] { "ConnectHistory" };
}

// 组策略
namespace DConfigKey {
inline constexpr char DiscoveryModeKey[] { "cooperation.discovery.mode" };
inline constexpr char TransferModeKey[] { "cooperation.transfer.mode" };
}

inline const char MainAppName[] { "dde-cooperation" };
inline const char CooperRegisterName[] { "daemon-cooperation" };

// Setting menu action list
enum MenuAction {
    kSettings,
    kDownloadWindowClient
};

#endif   // TYPE_DEFINES_H
