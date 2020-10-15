# h2 
## ex1
**No OJ score**
### function
- ex1: main function
- check: check leap year
### code
<details>
<summary>click me</summary>

```matlab
function ex1()
    while true    
        year=input('Please input one year (Since 1582):','s');%Gregorian calendar was not used before 1582
        l=strlength(year);
        flag=true;
        for i=1:l
            if year(i)<'0' || year(i)>'9'
                flag=false;
                break;
            end
        end
        if (flag==true && str2num(year)>=1582)  
            check(str2num(year));
            return;
        end
        disp('Not a available datum');
    end
end
function check(x)
    if (mod(x,4)==0) && ((mod (x,400)==0)||mod(x,100)~=0)
        disp('A leap year');
    else
        disp('Not a leap year');
    end
end
```
</details>

## ex2
[**OJ score: 100/100**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f74153f91df0600061c44e1)
### function
- ex2: main function
- printnum: print ans in the given form
### code
<details>
<summary>click me</summary>

```matlab
function ex2()
    x=input('');
    n=floor(x/4);
    while true
        p=4*n+1;
        if p<=x 
            p=p+4;
        end
        if (isprime(p)==true)
            maxi=floor(sqrt(p));
            flag=false;
            for i=1:maxi
                if sqrt(p-i*i)==floor(sqrt(p-i*i))
                    flag=true;
                    break;
                end
            end
            if (flag==true) 
                printnum(p,i,p-i*i);
                return;
            end
        end
        n=n+1;
    end
end
function printnum(x,y,z)
    str=num2str(x)+" = "+num2str(y)+"^2 + "+num2str(sqrt(z))+"^2";
    disp(str);
end
```

</details>

## ex3
**No OJ score**
### function
- ex3: main function
- getnum: input number ***(use recursion)***
- printnum: assign decimal, million,thousand and the left into other functions
- checkflag: check space
- hun_print: print every part from 000 to 999
- print_digit: find decimal part
- print_09: print decimal part
### code
  
<details>
<summary>click me</summary>

```matlab
function ex3()
    [num,snum]=getnum();
    zero_flag=0;
    if (num<0) %negative number
        [zero_flag]=checkflag(zero_flag);
        fprintf('negative');
        num=-num;
    end
    if (num==0)
        [zero_flag]=checkflag(zero_flag);
        fprintf("zero");
        return;
    end
    printnum(num,zero_flag,snum);
end
function [num,snum]=getnum()
    snum=input('PLEASE INPUT A NUM x (abs(x)<=999,999,999 and allow decimal) : ','s');
    [num,check]=str2num(snum);
    if (check==0 || abs(num)>999999999)
        disp('ERROR: NOT A NUM or ABS TOO LARGE');
        num=getnum();%Recursion
    end
end
function printnum(x,zero_flag,snum)
    if (x<1) 
        [zero_flag]=checkflag(zero_flag);
        fprintf('zero dot');
        print_digit(snum,zero_flag);
        return;
    end
    high_flag=true;% flag whether "and" is needed
    million_num=fix(x/1000000);
    if (million_num>0)
        [zero_flag,high_flag]=hun_print(million_num,zero_flag,high_flag);
        fprintf(' million');
    end
    thousand_num=fix(mod(fix(x/1000),1000));
    if (thousand_num>0)
        [zero_flag,high_flag]=hun_print(thousand_num,zero_flag,high_flag);
        fprintf(' thousand');
    end
    lowest_num=fix(mod(x,1000));
    if (lowest_num>0)
        [zero_flag,high_flag]=hun_print(lowest_num,zero_flag,high_flag);
    end
    if (x-fix(x)~=0) % decimal part
        fprintf(' dot');
        print_digit(snum,zero_flag);
    end
end
function [zero_flag]=checkflag(zero_flag)% check whether there are a space
    if zero_flag==1 
        fprintf(' ');
    end
    zero_flag=1;
end
function [zero_flag,high_flag]=hun_print(x,zero_flag,high_flag)   
    ONE=["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"];
    TEN=["ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"];
    if x>=100;
        [zero_flag]=print_09(num2str(fix(x/100)), zero_flag);
        fprintf(' hundred');
    end
    
    % check and
    if (mod(x,100)~=0 && high_flag==false && x<100)
        fprintf(' and');
    end
    if (mod(x,100)~=0 && x>=100 )
        fprintf(' and');
    end
    
    % check x00-x99
    high_flag=false;
    if (mod(x,100)~=0)
        [zero_flag]=checkflag(zero_flag);
        if mod(x,100)<=19
            fprintf(ONE(mod(x,100)));
        end
        if mod(x,100)>=20
            fprintf(TEN(fix(mod(x,100)/10)));
            fprintf(' ');
            if mod(x,10)>0
                fprintf(ONE(mod(x,10)));
            end
        end
    end   
end
function print_digit(snum,zero_flag)
    l=length(snum);
    for i=1:l
        %check decimal part
        if snum(i)=='.'
            break;
        end
    end
    for j=i+1:l
        [zero_flag]=print_09(snum(j),zero_flag);
    end
end
function [zero_flag]=print_09(x,zero_flag)
    % print decimal part
    [zero_flag]=checkflag(zero_flag);
    switch x
            case '0'
                fprintf('zero');
            case '1'
                fprintf('one');
            case '2'
                fprintf('two');
            case '3'
                fprintf('three');
            case '4'
                fprintf('four');
            case '5'
                fprintf('five');
            case '6'
                fprintf('six');
            case '7'
                fprintf('seven');
            case '8'
                fprintf('eight');
            case '9'
                fprintf('nine');
        end
end
```

</details>

### feature
- allow negative number
- allow number with decimal

## ex4
**OJ score: 100/100**
[random](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f7608a891df0600061c4f65)
[iterative](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f7608f291df0600061c4f83)
[recursive](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f76096591df0600061c4fb3)

### function
- ex4: choose one way
- ex4_iterative: use iterative to solve the problem
- ex4_recursive: use recursive to solve the problem

### code

<details>
<summary>random</summary>

```matlab
function ex4()
    format longg;
    choice=randi(2);%randomly choose one 
    if choice==1
        ex4_iterative();
    else
        ex4_recursive(true);
    end
end
function ex4_iterative()
    i=3;
    f=input('');
    x=double(input(''));
    precision=input('');
    while true
        x(i)=(x(i-2)*f(x(i-1))-x(i-1)*f(x(i-2)))./(f(x(i-1))-f(x(i-2)));
        if abs(x(i)-x(i-1))<power(10,-(precision+2))
            disp (round((x(i))*power(10,precision))/power(10,precision));
            return;
        end
        i=i+1;
    end
end
function ex4_recursive(flag)
    persistent f precision x; %use persistent var to save memory
    if flag == true
        f=input('');
        x=double(input(''));
        precision=input('');
    end
    if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(1)=((x(1)*f(x(2))-x(2)*f(x(1)))./(f(x(2))-f(x(1))));
     if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(2)=((x(2)*f(x(1))-x(1)*f(x(2)))./(f(x(1))-f(x(2))));
    ex4_recursive(false);
end
```

</details>

<details>
<summary>iterative</summary>

```matlab
function ex4()
    format longg;
    %choice=randi(2);%randomly choose one 
    %if choice==1
        ex4_iterative();
    %else
    %    ex4_recursive(true);
    %end
end
function ex4_iterative()
    i=3;
    f=input('');
    x=double(input(''));
    precision=input('');
    while true
        x(i)=(x(i-2)*f(x(i-1))-x(i-1)*f(x(i-2)))./(f(x(i-1))-f(x(i-2)));
        if abs(x(i)-x(i-1))<power(10,-(precision+2))
            disp (round((x(i))*power(10,precision))/power(10,precision));
            return;
        end
        i=i+1;
    end
end
function ex4_recursive(flag)
    persistent f precision x; %use persistent var to save memory
    if flag == true
        f=input('');
        x=double(input(''));
        precision=input('');
    end
    if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(1)=((x(1)*f(x(2))-x(2)*f(x(1)))./(f(x(2))-f(x(1))));
     if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(2)=((x(2)*f(x(1))-x(1)*f(x(2)))./(f(x(1))-f(x(2))));
    ex4_recursive(false);
end
```

</details>

<details>
<summary>recursive</summary>

```matlab
function ex4()
    format longg;
    %choice=randi(2);%randomly choose one 
    %if choice==1
    %    ex4_iterative();
    %else
        ex4_recursive(true);
    %end
end
function ex4_iterative()
    i=3;
    f=input('');
    x=double(input(''));
    precision=input('');
    while true
        x(i)=(x(i-2)*f(x(i-1))-x(i-1)*f(x(i-2)))./(f(x(i-1))-f(x(i-2)));
        if abs(x(i)-x(i-1))<power(10,-(precision+2))
            disp (round((x(i))*power(10,precision))/power(10,precision));
            return;
        end
        i=i+1;
    end
end
function ex4_recursive(flag)
    persistent f precision x; %use persistent var to save memory
    if flag == true
        f=input('');
        x=double(input(''));
        precision=input('');
    end
    if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(1)=((x(1)*f(x(2))-x(2)*f(x(1)))./(f(x(2))-f(x(1))));
     if (abs(x(1)-x(2))<power(10,-(precision+2)))
        disp (round((x(1))*power(10,precision))./power(10,precision));
        return;
    end
    x(2)=((x(2)*f(x(1))-x(1)*f(x(2)))./(f(x(1))-f(x(2))));
    ex4_recursive(false);
end
```

</details>

## ex5
**[OJ score: 100/100](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f7615a791df0600061c50d3)**

### function
- ex5: calculate power and enumerate ans
- check: check whether is ans

### code
<details>
<summary>click me</summary>

```matlab
function ex5()
    n=input('');
    flag=false;
    for j=1:10
        for i=1:10
            P(i,j)=power(i-1,j);
        end
    end
    while true
        [flag]=check(n,P);
        if flag==true 
            return;
        end
        n=n+1;
    end
end
function [flag]=check(x,P)
    temp=x;
    i=0;
    while (temp>0)
        i=i+1;
        A(i)=mod(temp,10);
        temp=fix(temp/10);
    end
    l=i;
    sum=0;
    flag=false;
    for i=1:l
        sum=sum+P(A(i)+1,l);
        if sum>x
            return;
        end
    end
    if sum==x
        disp(x);
        flag=true;
        return;
    end
end
```

</details>

## ex6
[**OJ score: 100/100**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f7621a791df0600061c50e5)

### function
- ex6: check the corresponding day of the week
### code
<details>
<summary>click me</summary>

```matlab
function ex6()
    date=input('');
    d=date(1);
    m=date(2);
    y=date(3);
    if m<=2 
        y=y-1;
    end
    m=mod(m+10,12);
    if (m==0) 
        m=12;
    end
    c=fix(y/100);
    y=mod(y,100);
    week=1+mod((d+fix((13*m-1)/5)+y+fix(y/4)+fix(c/4)-2*c),7);
    switch week
        case 1
            disp('Sunday');
        case 2
            disp('Monday');
        case 3
            disp('Tuesday');
        case 4
            disp('Wednesday');
        case 5
            disp('Thursday');
        case 6
            disp('Friday');
        case 7
            disp('Saturday');
    end
end
```
</details>