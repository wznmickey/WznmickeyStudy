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