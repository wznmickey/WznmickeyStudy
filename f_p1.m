function f_p1()
    [n,w,p,car]=init_car();
    [g,o,r]=init_light();
    go(r,o,g,w,p,n,car);
end
function [car]=assign(n)
% use 3 number to cut 1..n into 4 parts, each part imply the number of cars
% on each line. The number of cars in each line is from 0 to n;
    temp_assign=randi(n,1,3);
    temp_assign=sort(temp_assign);
    car(1).num=temp_assign(1);
    car(2).num=temp_assign(2)-temp_assign(1);
    car(3).num=temp_assign(3)-temp_assign(2);
    car(4).num=cast(n-temp_assign(3),'uint64');
end
function [n,w,p,car]=init_car()
    stfn='The total number of cars is :(int, from 10 to 32767)';
    stfw='The width of the road is :(int, from 3 to 10)';
    stfp='The probability that a cars does not stop at the red light is:(real number, from 0.0 to 1.0)';
    n=input(stfn);
    w=input(stfw);
    p=input(stfp);
    car=assign(n);
end
function [g,o,r]=init_light()
    color=["green","orange","red"];
    temp_st1="The time for ";
    temp_st2=" light is:";
    g=input(temp_st1+color(1)+temp_st2);
    o=input(temp_st1+color(2)+temp_st2);
    r=input(temp_st1+color(3)+temp_st2);
    if (g+o~=r) 
        disp("ERROR!");
        disp("The time for green plus the time for orange does not equal to the time for red.It will lead to traffic accidents.Please input again.");
        [g,o,r]=init_light();
   end
end
function [time,x,y]=start()
    time=0;
    x.light.status=3;% 1-r,2-o(y),3-g
    x.light.time=0;
    y.light.status=1;
    y.light.time=0;
end
function [x]=checklight(time,x,r,o,g)
    x.light.time=x.light.time+1;
    if (x.light.status==2 && x.light.time>=o)
        x.light.status=1;
        x.light.time=0;
    end
    if (x.light.status==1 && x.light.time>=r)
        x.light.status=3;
        x.light.time=0;
    end
    if (x.light.status==3 && x.light.time>=g)
        x.light.status=2;
        x.light.time=0;
        if (o==0)
            x.light.status=1;
            x.light.time=0;
        end
    end
end
function draw_crossroad(w)
    figure;
    w=w/2;
    xn=linspace(-30,-w,100);
    yn=linspace(-30,-w,100);
    xp=linspace(w,30,100);
    yp=linspace(w,30,100); 
    x1=xn*0-w;
    x2=-x1;
    x3=xn*0;
    y1=yn*0+w;
    y2=-y1;
    y3=yn*0;
    hold on; 
    plot(xn,y1,'black');
    plot(xn,y2,'black');
    plot(xp,y1,'black');
    plot(xp,y2,'black');
    plot(x1,yn,'black');
    plot(x2,yn,'black');
    plot(x1,yp,'black');
    plot(x2,yp,'black');
    plot(xn,y3,'--black');
    plot(xp,y3,'--black');
    plot(x3,yn,'--black');
    plot(x3,yp,'--black');
    xlim([-30 30]);
    ylim([-30 30]);
end
function draw_light(x,y,w,an1,an2)
    w=w/2;
    color=["r","#ffa500","g"];
    clearpoints(an1);
    an1 = animatedline('Color',color(x.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(x.light.status));
    addpoints(an1,w,w);
    addpoints(an1,-w,-w);
    an2 = animatedline('Color',color(y.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(y.light.status));
    addpoints(an2,-w,w);
    addpoints(an2,w,-w);
end
function go(r,o,g,w,p,n,car)
    [time,x,y]=start();
    draw_crossroad(w);
    an1 = animatedline;
    an2 = animatedline;
    while true %to be updated in milestone 2, checking car
        pause(1);
        time=time+1;
        [x]=checklight(time,x,r,o,g);
        [y]=checklight(time,y,r,o,g);
        draw_light(x,y,w,an1,an2);
        drawnow;
    end
end