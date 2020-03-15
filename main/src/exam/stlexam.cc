#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <typeinfo>
#include "stlexam.h"

using namespace std;

// vector, array, deque, list, set, map, multimap, unorderedmap, stack, queue, priority_queue
void stlexam() {
    vectorexam();
}

void vectorexam() {
    std::vector<int> vi{};

    int i1 = 1;
    int i2 = 2;

    vi.push_back(i1); //copy of value
    vi.push_back(i2); //copy of value

    std::clog << vi[0] <<std::endl;
    vi[0] = 3;
    std::clog << vi[0] <<std::endl;
    std::clog << i1 <<std::endl;
}

void setexam1() {
    set<int> s;

    pair<set<int>::iterator, bool> pr;
    pr = s.insert(50);    // insert 결과 pair 반환
    s.insert(40);
    s.insert(80);

    if (true == pr.second)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
        cout << *pr.first << "가 이미 있습니다. 삽입 실패! " << endl;

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    pr = s.insert(50);        // 중복 값 insert
    if (true == pr.second)
        cout << *pr.first << " 삽입 성공!" << endl;
    else
        cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

    for (iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    s.insert(pr.first, 60);        // 50 위치에 값 50 바로 삽입

    for (iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    set<int, greater<int>> s2;        // 내림차순 정렬
    s2.insert(50);
    s2.insert(30);
    s2.insert(80);
    s2.insert(40);
    s2.insert(10);
    s2.insert(70);
    s2.insert(90);

    for (iter = s2.begin(); iter != s2.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    // key_compare, value_compare 확인
    cout << "key_compare less : " << typeid(s.key_comp()).name() << endl;
    cout << "key_compare greater : " << typeid(s2.key_comp()).name() << endl;

    cout << "value_compare less : " << typeid(s.value_comp()).name() << endl;
    cout << "value_compare greater : " << typeid(s2.value_comp()).name() << endl;

    /*
        결과 :
        50 삽입 성공!
        40 50 80
        50가 이미 있습니다. 삽입 실패!
        40 50 80
        40 50 60 80
        90 80 70 50 40 30 10
        key_compare less : struct std::less<int>
        key_compare greater : struct std::greater<int>
        value_compare less : struct std::less<int>
        value_compare greater : struct std::greater<int>
    */
}

void setexam2() {
    set<int> s;

    s.insert(40);
    s.insert(30);
    s.insert(50);
    s.insert(80);
    s.insert(10);
    s.insert(90); 
    s.insert(70);

    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // count는 해당 원소의 개수를 반환한다. set은 중복을 허용하지 않으므로 1 또는 0이다.
    cout << "원소 50의 개수 : " << s.count(50) << endl;
    cout << "원소 100의 개수 : " << s.count(100) << endl;

    // find는 해당 원소를 찾는다. 원소가 없으면 end() 를 반환한다.
    iter = s.find(30);
    if (iter != s.end())
        cout << *iter << "가 s에 있다" << endl;
    else
        cout << "30이 s에 없다." << endl;


    set<int>::iterator iter_lower;
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30);        // 30 원소의 첫번째
    iter_upper = s.upper_bound(30);        // 30 원소 마지막의 다음 원소
    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);

    // 55의 첫번째 원소와 다음원소를 가리키는 iter가 같으면 값이 없다
    if (iter_lower != iter_upper)        
        cout << "55가 s에 있다" << endl;
    else
        cout << "55가 s에 없다" << endl;


    // equal_range는 해당 원소의 범위를 pair로 반환한다.
    pair<set<int>::iterator, set<int>::iterator> iter_pair;

    iter_pair = s.equal_range(30);
    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);
    if (iter_pair.first != iter_pair.second)
        cout << "55가 s에 있다 " << endl;
    else
        cout << "55가 s에 없다 " << endl;

    /*
        결과 :
        10 30 40 70 80 90
        원소 50의 개수 : 1
        원소 100의 개수 : 0
        30가 s에 있다
        30
        40
        55가 s에 없다
        30
        40
        55가 s에 없다
    */
}