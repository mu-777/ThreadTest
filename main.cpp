#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// ref http://minus9d.hatenablog.com/entry/20130914/1379168684


// グローバル領域にmtxを用意
std::mutex mtx[4];

void worker(int &id) {
    // 共通の資源（ここでは標準出力）を使う前にロックをかける
    int _id = id;
    mtx[_id].lock();

    // 資源を使った処理を行う
    for (int i = 0; i < 10; i++) {
        std::cout << _id << ": thread id: " << std::this_thread::get_id() << " " << i << std::endl;
    }

    // 使い終わったらロックを外す
    mtx[_id].unlock();
}

int main() {

    int i = 0;
    // スレッドを4つ作る
    std::vector<std::thread> ths(4);
    for (auto &th : ths) {
        th = std::thread(worker, std::ref(i));
        i++;
    }

    // すべてのスレッドが終わるのを待つ
    for (auto &th : ths) {
        th.join();
    }

    return 0;
}