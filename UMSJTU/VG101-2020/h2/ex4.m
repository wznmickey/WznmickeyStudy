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