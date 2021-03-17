# ex1

input: c,n,a(the length of the square)
output: the motion
```
function call_f_1()
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
```

I check the position every 0.2seconds, checking the direction and location, which make the code easier.


## ex2
```
Move plate 1 from Chi to Kan
Move plate 2 from Chi to Box
Move plate 1 from Kan to Box
Move plate 3 from Chi to Kan
Move plate 1 from Box to Chi
Move plate 2 from Box to Kan
Move plate 1 from Chi to Kan
```
total 7 steps

First move the nth to Kan , then move n-1 plates from Chi to Kan 