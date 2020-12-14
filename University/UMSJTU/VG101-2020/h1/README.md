# README of h1

## About README (Ex.1)

***In brief, README is the cover of a project.***

### What does README include?

Usually there will be a README in a project, which can let people who first know the project get a **general understangding** about the project, knowing **what** problem the project is aiming to solve, **how** to use the products in the project (such as how to download, install and config) and **how** to contribute to the project(money or code or ways to discuss besides issue). Also, there will be a link to the [**license**](https://opensource.org/licenses/) (ruled how others can use the project) the project obeyed and **thanks**.

### Who can and should maintain and change the README?

**Everyone** who contributes to the project can and should do so if necessary.

### How to write a README?

Usually it is written by Markdown(.md), which is a kind of format that can be **easily** written without the limit of software and **correctly** identified in Windows, Mac OS, Linux etc. . We people can read it **without** computer which is differ from .doc. Its rules are owned by the world. Through several signs we can mark words with different size such as what you already see.You can learn more about Markdown by click [me](https://www.markdownguide.org/).

### License

[MIT](https://choosealicense.com/licenses/mit/)

### Reference

 - [Make a README][1] 
 - [README in Hexo][2]

## Basic MATLAB knowledge (Ex.2) 

**OJ score: 10/10**

### Failed Reason

 - I failed to find that it should be named in lower cases and was influenced by the "cp: cannot stat '/in/ex2.m': No such file or directory" ,so I tried many times to find the folder "in".
 - I didn't have an enough understanding about English, so very often I was puzzled by the discription of several steps.

### Idea

 - Let each function do one step.
 - Let the operation of reseting as a function which is used in every step.

### To be optimized

No.

### Final code

<details>
<summary>Look</summary>

```MATLAB
[x,y]=Ex2_step1();
[x,y]=Ex2_step2(x,y);
[x,y]=Ex2_step3(x,y);
[x,y]=Ex2_step4(x,y);
[x,y,z]=Ex2_step5(x,y);
[x,y,z,w]=Ex2_step6(z);
[x,y]=Ex2_step7(x,y,w);
function [x,y]=Ex2_init()
    x=[3;2;6;8];
    y=[4;1;3;5];
end
function [x,y]=Ex2_step1()    
    [x,y]=Ex2_init();
    disp(x)
    disp(y)
    Ex2_init();% Because specifications 2, after question 1, there still be a reset.
end
function [x,y]=Ex2_step2(x,y)
    y(5)= sum(x);
    disp(x);
    disp(y);
    [x,y]=Ex2_init();
end
function [x,y]=Ex2_step3(x,y)
    x=x.^y;
    disp(x);
    disp(y);
    [x,y]=Ex2_init();
end
function [x,y]=Ex2_step4(x,y)
    y=x.\y;
    disp(y);
    disp(x);
    [x,y]=Ex2_init();
end
function [x,y,z]=Ex2_step5(x,y)     
    z=x.*y;
    disp(x);
    disp(y);
    disp(z);
    [x,y]=Ex2_init();
end
function [x,y,z,w]=Ex2_step6(z)
    w=sum(z);
    disp(z);
    disp(w);
    [x,y]=Ex2_init();% Because specifications 2, even there is no chagnge of x and y, there still be a reset.
end
function [x,y]=Ex2_step7(x,y,w)
    disp(x);
    disp(y);
    disp(w);
    disp(x'*y-w);
    [x,y]=Ex2_init();% because specifications 2
    % The result comes from the action that firstly, multiplies the nonconjugate transpose of x and
    % y by multiplying corresponding elements and then minus w.
end
```

</details>

## Simple scripting in MATLAB (Ex.3)

**OJ score: 10/10**

### Failed Reason

 - I didn't find the difference of double quotation marks and single quotation marks, and thus failed because of wrong input.

### Idea

 - Since the number of data is known, just looping 1000 times is okay.

### To be optimized

No.

### Final code

<details>
<summary>Look</summary>

```matlab
for i=1:1000 %Having know the total number 1000
    t_s=input('');
    t_d=t_s/(24*60*60);
    disp(t_d);
end
```

</details>

## Basic scripting (EX.4)

**OJ score: 10/10**

### Failed Reason

 - I misunderstood the discription and printed an "and" between two numbers.
 - I misoutputed the meters have to run to arrive next lap to the meters having run after previous lap.

### Idea

 - Use mod to get the left meters after previous lap.
 - Minus the left meters and then be divided 400 to get the laps.
 - By being minused by 400 , get meters have to run to arrive next lap.

### To be optimized

 - I now do not use idivide because I don't know whether I should use int16 or int32 or other type since the range of input is not given.

### Final code

<details>
<summary>Look</summary>

```matlab
l=input('');
left=mod (l,400);
lap=(l-left)/400;% can also use idivide
left=400-left;
disp(lap);
disp(left);
```

</details>

## Algorithms (Ex.5)

**OJ score: 10/10**

### Algorithm

Input: 
 - d (distance between Alexandria and Aswan)
 - l1 (the length of shadow of one building in Alexandria on at noon)
 - l2 (the height of the building)

Output: 
 - c (circumference of the Earth)
 - r (radius of the Earth)

1. angle1 <- arctan(l2/l1) (in degree measure);
2. angle2 <- 0;
3. fangle <- angle1-angle2;
4. d_per_angle <- d/fangel;
5. c <- d_per_angle*360;
6. return c;
7. r <- c/(2*pi);
8. return r;

### Failed Reason

 - be puzzled with various versions of Eratosthenes' story, which have many difference between them on the data he collected and the answer he got.

### Idea

 - use trigonometry

### To be optimized

No.

### Final code

<details>
<summary>Look</summary>

```matlab
%reference: wiki
angel=7.2;
meter=5000*160;
meter_per_angel=meter/angel;
c=meter_per_angel*360;
disp(c/1000);
r=c/2/pi;
disp(r/1000);
```

</details>

### Reference

 - [wiki1][3] 
 - [wiki2][4]
  
## Vectors (Ex.6)

**OJ score: 10/10**

### Failed Reason

 - not tell string from char array firstly 

### Idea

 - use if to check which type of change is needed

### To be optimized

 - Rewrite by using case to make the code more beautiful.(But I am not sure how to rewrite it.)

### Final code

<details>
<summary>Look</summary>

```matlab
data=input('');
type=input('','s');
if (strcmp('stones to pounds',type)) % char array can be checked whether they "=="  only when they have the same length (num of elements in the array) 
    fans=14.*data;
elseif (strcmp(type,'pounds to kg'))
    fans=(6.35/14).*data;
else fans=data/6.35;
end
disp(fans);
```

</details>

## Compact coding (Ex.7)

**No OJ checking**

### Idea

 - use functions provided by MATLAB

### To be optimized

No.

### Final code

<details>
<summary>Look</summary>

```matlab
ans1=primes(100000)% from 1 to 100000
ans2=prod(randi(10,1,5))% get a 1*5 random int from 1 to 10 and then get the product
```

</details>

[1]:https://www.makeareadme.com/
[2]:https://github.com/hexojs/hexo/blob/master/README.md
[3]:https://en.wikipedia.org/wiki/Eratosthenes
[4]:https://en.wikipedia.org/wiki/Earth%27s_circumference