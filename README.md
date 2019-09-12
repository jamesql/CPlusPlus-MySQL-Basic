# Basic C++ MySQL Setup
Basic Setup for MySQL For C++
# Where to get MySQL Connecter 8 for C++?
- [Click Here!](https://dev.mysql.com/doc/connector-cpp/8.0/en/)
# Connection String
```cpp
"tcp://127.0.0.1:3306", "root", "Password"
```

# Basic Includes
```cpp
#include "jdbc/mysql_connection.h"
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
```

# Namespace
```cpp
using namespace ::sql;
```
# Basic Objects
```cpp
Driver *driver;
Connection *con;
Statement *stmt;
ResultSet *res;
```

# Initilize Driver & Connect
```cpp
driver = get_driver_instance();
```
```cpp
con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
```
In a method :
```cpp
void connectDatabase() {
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "JagroshSucks1337");
}

void disconnectDb() {
    con->close();
    delete con;
}
```

# Query w/ Result Set
```cpp
ResultSet* query(std::string statement) {
    ResultSet *newRes;
    stmt = con->createStatement();
    newRes = stmt->executeQuery(statement);
    return newRes;
}
```

# Full Basic File
```cpp
#include "jdbc/mysql_connection.h"
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace ::sql;

Driver *driver;
Connection *con;
Statement *stmt;
ResultSet *res;

void connectDatabase() {
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
}

void disconnectDb() {
    con->close();
    delete con;
}

void setSchema(std::string db) {
    con->setSchema(db);
}

ResultSet* query(std::string statement) {
    ResultSet *newRes;
    stmt = con->createStatement();
    newRes = stmt->executeQuery(statement);
    return newRes;
}

int main() {
  connectDatabase();
  setSchema("database");
  ResultSet *r = query("SELECT * FROM database");
  while(r->next()) {
    cout << res->getString(1) << endl;
  }
  disconnectDb();
  return 0;
}
```
