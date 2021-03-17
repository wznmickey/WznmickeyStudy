function call_f_1()
    c=input("the center=?");
    a=input("the length=?");
    n=input("the times=?");
    i=0;
    dire=rand()*360/2/pi;
    x=c;
    y=c;
    xi=0;
    yi=0;
    draw_intial(x,y,c,a);
    while (i<=n)
        rectangle('Position',[c-a/2,c-a/2,a,a]); 
        axis ([c-2*a c+2*a c-2*a c+2*a],'equal');
        [i,x,y,xi,yi,dire]=check(i,a,x,y,xi,yi,dire);
        pause(0.2);
        plot(x,y,'o');
    end
end
function draw_intial(x,y,c,a)
    plot(x,y,'o');
    rectangle('Position',[c-a/2,c-a/2,a,a]); 
    axis ([c-2*a c+2*a c-2*a c+2*a],'equal');
end
function [i,x,y,xi,yi,dire]=check(i,a,x,y,xi,yi,dire)
    x=x+sin(dire)*0.2;
    y=y+cos(dire)*0.2;
    xi=xi+sin(dire)*0.2;
    yi=yi+cos(dire)*0.2;
    if abs(xi)>=a/2
        dire=-dire;
        i=i+1;
    else if abs(yi)>=a/2
        dire=pi-dire;
        i=i+1;
        end
    end
end