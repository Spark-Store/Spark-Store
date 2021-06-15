/*
 * Copyright (C) 2015 ~ 2017 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DOBJECT_P_H
#define DOBJECT_P_H

#include "dtkcore_global.h"

DCORE_BEGIN_NAMESPACE

class DObject;
class DObjectPrivate
{
public:
    virtual ~DObjectPrivate();

protected:
    DObjectPrivate(DObject *qq);

    DObject *q_ptr;

    Q_DECLARE_PUBLIC(DObject)
};

DCORE_END_NAMESPACE

#endif // DOBJECT_P_H

