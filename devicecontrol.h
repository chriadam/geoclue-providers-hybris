/*
    Copyright (C) 2015 Jolla Ltd.
    Contact: Aaron McCarthy <aaron.mccarthy@jollamobile.com>

    This file is part of geoclue-hybris.

    Geoclue-hybris is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License.
*/

#ifndef DEVICECONTROL_H
#define DEVICECONTROL_H

#include <QtCore/QObject>

QT_FORWARD_DECLARE_CLASS(QDBusVariant)

class DeviceControl : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool Powered READ powered WRITE setPowered NOTIFY poweredChanged)

public:
    explicit DeviceControl(QObject *parent = 0);

    bool powered() const;
    void setPowered(bool powered);

signals:
    void PropertyChanged(const QString &name, const QDBusVariant &value);
    void poweredChanged();

private:
    bool m_powered;
};

#endif // DEVICECONTROL_H
