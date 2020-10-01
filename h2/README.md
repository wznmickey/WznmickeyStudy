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
        year=input('Please input one year (Since 1598):','s');%Gregorian calendar was not used before 1598
        l=strlength(year);
        flag=true;
        for i=1:l
            if year(i)<'0' || year(i)>'9'
                flag=false;
                break;
            end
        end
        if (flag==true && str2num(year)>=1598)  
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
[**OJ score 100/100**](https://joj.sjtu.edu.cn/d/vg101_fall_2020_manuel/records/5f74153f91df0600061c44e1)
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

### feather
- allow negative number
- allow number with decimal