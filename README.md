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
