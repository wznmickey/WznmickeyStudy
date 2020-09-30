# h2 
## ex1
**No OJ score**
### function
- ex1(): input a valid year and call check(X)
- check(x): check whether x is a leap year
### code
<details>
<summary>click me</summary>

```matlab
function ex1()
    while true    
        year=input('Please input one year:','s');
        l=strlength(year);
        flag=true;
        for i=1:l
            if year(i)<'0' || year(i)>'9'
                flag=false;
            end
        end
        if flag==true 
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
- ex2(): find p,a,b and call printnum(p,a,b)
- printnum(x,y,z): print x,y,z in the given form
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
