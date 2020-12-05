function ex5()
    format longg;
    f=input('');
    x=input('');
    left=x(1);
    right=x(2);
    while(right-left>=0.0001)
        mid=(left+right)/2;
        f1=f(left);
        f2=f(mid);
        f3=f(right);
        if f1*f2<0
            right=mid;
            continue;
        end
        if f2*f3<0
            left=mid;
            continue;
        end
        if f1==0 
            disp(round(left,3));
        end
        if f2==0
            disp(round(mid,3));
        end
        if f3==0
            disp(round(right,3));
        end
    end
    disp(round(left,3));        
end