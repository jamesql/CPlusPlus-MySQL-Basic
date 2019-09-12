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

