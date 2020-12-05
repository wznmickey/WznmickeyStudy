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