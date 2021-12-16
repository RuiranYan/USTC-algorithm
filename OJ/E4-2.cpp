/*
 * 任务调度问题:
 * 现有N个任务需要在一台机器上进行调度，其中每个任务有相应的到达时间r_i和执行时间p_i。
 * 任务必须在到达之后才能进行执行，该机器同时只能执行一个任务。
 * 当一个任务在机器上执行p_i时间后，该任务即视为完成。完成时刻为f_i，则响应时间为f_i-r_i
 * 我们需要找到一个调度方案使所有任务的响应时间之和最短。
 * 需要说明的是，在这个问题里我们假设已经将时间划分为若干不可再分的时隙，即一个任务最少的执行时间为1个单位时间，
 * 且任务只会在整数时刻到达。
 * 此外，调度是可抢占的
 * 这意味着在任意时隙开始时可以通过挂起正在执行的任务i转而执行另一项任务j，随后可以恢复任务i并执行其剩余的工作。
 * INPUT:
 * 第一行输入任务数n
 * 接下来n行每行输入两个整数表示任务的到达时间和执行时间
 * OUTPUT:
 * 输出一个整数表示最小的所有任务的总响应时间。
 */

# include <iostream>
# include <algorithm>
# include <queue>

using namespace std;
typedef struct task {
    int r;
    int p;

    friend bool operator<(task a, task b) {
        return a.p > b.p;
    }
} task;

task a[100000];
int s[100000];
int f[100000];

bool cmp(task x, task y) {
    return x.r < y.r;
}

int main() {
    int n;
    cin >> n;
    int all_time = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].r >> a[i].p;
    }
    sort(a, a + n, cmp);
    priority_queue<task> q;
    int k = 0;
    int j = 0;
    int time = 0;
    while (1) {
        if (q.empty()) {
            if (k == n) break;
            else {
                time = a[k].r;
                q.push(a[k]);
                k++;
            }
        } else if (k == n || a[k].r >= time + q.top().p) {
            task e = q.top();
            time += e.p;
            s[j] = e.r;
            f[j] = time;
            q.pop();
            j++;
        } else{
            task e = q.top();
            e.p -= a[k].r-time;
            time = a[k].r;
            q.pop();
            q.push(e);
            q.push(a[k]);
            k++;
        }
    }
    for (int i = 0; i < n; ++i) {
        all_time += f[i]-s[i];
    }
    cout << all_time;
    return 0;
}
