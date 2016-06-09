/**
 *    Copyright (C) 2016 Terark Inc.
 *    This file is heavily modified based on MongoDB WiredTiger StorageEngine
 *    Created on: 2015-12-01
 *    Author    : leipeng, rockeet@gmail.com
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the GNU Affero General Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */
#ifdef _MSC_VER
#pragma warning(disable: 4800) // bool conversion
#pragma warning(disable: 4244) // 'return': conversion from '__int64' to 'double', possible loss of data
#pragma warning(disable: 4267) // '=': conversion from 'size_t' to 'int', possible loss of data
#endif

#include "mongo/platform/basic.h"

#include "terarkdb_server_status.h"

#include "mongo/base/checked_cast.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "terarkdb_kv_engine.h"
#include "terarkdb_record_store.h"
//#include "terarkdb_recovery_unit.h"
//#include "terarkdb_session_cache.h"
//#include "terarkdb_util.h"
#include "mongo/util/assert_util.h"
#include "mongo/util/scopeguard.h"

namespace mongo { namespace terarkdb {

using std::string;

TerarkDbServerStatusSection::TerarkDbServerStatusSection(TerarkDbKVEngine* engine)
    : ServerStatusSection(kTerarkDbEngineName), _engine(engine) {}

bool TerarkDbServerStatusSection::includeByDefault() const {
    return true;
}

BSONObj
TerarkDbServerStatusSection::generateSection(OperationContext* txn,
                                           const BSONElement& configElement) const {
    BSONObjBuilder bob;

//    TerarkDbRecoveryUnit::appendGlobalStats(bob);

    return bob.obj();
}

} } // namespace mongo::terarkdb
