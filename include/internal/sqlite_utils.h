#pragma once

#include <string>
#include <assert.h>
#include <thread>

#include "status.h"
#include "sqlite3.h"
#include "exception_utils.h"
#include "constants.h"

namespace jonoondb_api {
class SQLiteUtils {
public:
  static void ClearAndResetStatement(sqlite3_stmt* statement) {
    //Reset all params back to null
    int sqliteCode1 = sqlite3_clear_bindings(statement);

    //Reset the statement so that it can be re-executed
    int sqliteCode2 = sqlite3_reset(statement);

    assert(sqliteCode1 == SQLITE_OK);
    assert(sqliteCode2 == SQLITE_OK || sqliteCode2 == SQLITE_CONSTRAINT);  //Duplicate key errors are reported as SQLITE_CONSTRAINT

    if (sqliteCode1 != SQLITE_OK)
      throw SQLException(sqlite3_errstr(sqliteCode1), __FILE__, "", __LINE__);

    if (sqliteCode2 != SQLITE_OK)
      throw SQLException(sqlite3_errstr(sqliteCode2), __FILE__, "", __LINE__);    
  }

  static int SQLiteGenericBusyHandler(void* input, int retryCount) {
    if (retryCount > SQLiteBusyHandlerRetryCount) {
      return 0;  //This will stop the retry attempts and SQLITE_BUSY will be returned to the caller
    }

    std::this_thread::sleep_for(SQLiteBusyHandlerRetryIntervalInMillisecs);

    return 1;
  }

  static void CloseSQLiteConnection(sqlite3* dbConnection) {
    if (dbConnection != nullptr) {
      if (sqlite3_close(dbConnection) != SQLITE_OK) {
        // Todo: Handle SQLITE_BUSY response here
      }
      dbConnection = nullptr;
    }
  }
};

}  // jonoondb_api
