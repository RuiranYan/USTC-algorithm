/*
 * 数据库2.0:
 * INSERT改为会多输入一个主键，FIND改为输出主键吗，其他条件相同。
 */
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, int> db;
    map<string, int>::iterator itr;
    char s[10];
    int id;
    while (1) {
        scanf("%s", s);
        if (s[0] == 'I') {
            scanf("%d %s", &id, s);
            db.insert(pair<string, int>(s, id));
        } else if (s[0] == 'F') {
            scanf("%s", &s);
            itr = db.find(s);
            if(itr != db.end()){
                printf("%d\n",itr->second);
            } else printf("-1\n");
        } else break;
    }
}

