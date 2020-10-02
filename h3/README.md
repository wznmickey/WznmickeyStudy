# h3

## ex1
[**OJ score: 10/10**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f7626d491df0600061c50fa)

## ex2
**No OJ score**
![picture](https://cdn.jsdelivr.net/gh/wznmickey/jsdeliver@MYSTUDY/JI%20VG101/homework/Snipaste_2020-10-02_20-09-15.png)

## ex3
[**OJ score: 10/10**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f763f0d91df0600061c50fd)

## ex4
**No OJ score**

You can see the answer in "ex4_output.txt".

## ex5
[**OJ score: 100/100**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f76d86691df0600061c5808)

- Input: f(x), [a,b]
- Output: r
1. Left=a;
2. Right=b;
3. Mid=(Left+Right)/2;
4. if (Right-Left)<0.0001 % to avoid potential problems with round(), use 0.0001 rather than 0.001
   1. r=Mid;
   2. return r;
5. if f(Left)f(Mid)<0 
   1. Right=Mid;
   2. go to 3;
6. if f(Mid)f(Right)<0 
   1. Left=Mid;
   2. go to 3;
7. if f(Left)==0 r=Left;
8. if f(Mid)==0 r=Mid; 
9.  if f(Right)==0 r=Right;
10. return r;

## ex6
**No OJ score**

You can see the answer in "ex6_output.txt".