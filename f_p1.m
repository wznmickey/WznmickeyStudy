function f_p1()
    disp("HELLO! Let's start.")
    [n,w,p,car,car_list]=init_car();
    [g,o,r]=init_light();
    go(r,o,g,w,p,n,car,car_list);
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
    %1-left
    %2-right
    %3-top
    %4-low
end
function [n,w,p,car,car_list]=init_car()
    stfn='What is the total number of cars ? \n (int, from 10 to 32767) \n input:';
    stfw='What is the width of the road ? \n (int, meters from 10 to 20, \n 1 unit=10 meters \n car speed : 10 m/s = 1 unit/s) \n input:';
    stfp='What is the probability that a cars does \n not stop at the red light ? \n (real number, from 0.0 to 1.0) \n input:';
    n=input(stfn);
    w=input(stfw);
    p=input(stfp);
    car=assign(n);
    car_list=get_car_info(car,w,p);
    car_list=get_car_name(car_list,n);
end
function car_list=get_car_info(car,w,p)
    num=0;
    for i=1:4
        for j=1:car(i).num
            num=num+1;
            car_list(num).line=i;
            car_list(num).rate=j;
            if (j==1)
                car_list(num).first=true;
            else
                car_list(num).first=false;
            end
            %car_list(num).name=get_car_name();
            %disp(car_list(num)); To test;
            if (rand+p>=1 &&  p>0 )
                car_list(num).ignore=true;
                car_list(num).really_ignore=false;
                % ignore - initial idea
                % really_ignore - result
            else
                car_list(num).ignore=false;
                car_list(num).really_ignore=false;
            end
            %car length=6m
            %car width =4m
            if j==1
                if i==1 
                    car_list(num).x=-w/2-3;
                    car_list(num).y=-w/2-2;
                end
                if i==2
                    car_list(num).x=w/2+3;
                    car_list(num).y=w/2+2;
                end
                if i==3
                    car_list(num).x=-w/2-2;
                    car_list(num).y=w/2+3;
                end
                if i==4
                    car_list(num).x=w/2+2;
                    car_list(num).y=-w/2-3;
                end
            else
                if i==1 
                    car_list(num).x=car_list(num-1).x-6-2;
                    car_list(num).y=-w/2-2;
                end
                if i==2
                    car_list(num).x=car_list(num-1).x+6+2;
                    car_list(num).y=w/2+2;
                end
                if i==3
                    car_list(num).x=-w/2+2;
                    car_list(num).y=car_list(num-1).y+6+2;
                end
                if i==4
                    car_list(num).x=w/2-2;
                    car_list(num).y=car_list(num-1).y-6-2;
                end
            end
        end
    end
end
function car_list=get_car_name(car_list,n)
    temp_letter= ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"];
    disp("GET PLATES.PLEASE WAIT.");
    [temp_name]=generate_permutations_adjusted(temp_letter,5,n)
    for i=1:n
        first=char(randi(26)+'A'-1);
        name=[first,temp_name(i,:)];
        car_list(i).name=append(name(:));
    end
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
    x.light.status=3;% 1-r,2-o,3-g
    x.light.time=0;
    y.light.status=1;
    y.light.time=0;
    x.light.change=true;
    y.light.change=true;
end
function [x]=checklight(time,x,r,o,g)
    x.light.time=x.light.time+time;
    if (x.light.status==2 && x.light.time>=o)
        x.light.status=1;
        x.light.time=x.light.time-o;
        x.light.change=true;
    end
    if (x.light.status==1 && x.light.time>=r)
        x.light.status=3;
        x.light.time=x.light.time-r;
        x.light.change=true;
    end
    if (x.light.status==3 && x.light.time>=g)
        x.light.status=2;
        x.light.time=x.light.time-g;
        x.light.change=true;
        if (o==0)
            x.light.status=1;
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
    hold off;
    xlim([-30 30]);
    ylim([-30 30]);
end
function draw_light(x,y,w,an1,an2,time)
    persistent last_output_time;
    if isempty(last_output_time)
        last_output_time=0;
    end
    w=w/2;
    color=["r","#ffa500","g"];
    hold on;
    if x.light.change==true
        clearpoints(an1);
        an1 = animatedline('Color',color(x.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(x.light.status));
        addpoints(an1,w,w);
        addpoints(an1,-w,-w);
    end
    if y.light.change==true
        clearpoints(an2);
        an2 = animatedline('Color',color(y.light.status),'LineStyle','none','Marker','o','MarkerSize',15,'MarkerFaceColor',color(y.light.status));
        addpoints(an2,-w,w);
        addpoints(an2,w,-w);
    end
    
    if (time.now-last_output_time>0.25)
        if (1/time.last>250) title("FPS>250");
        else title("FPS:"+num2str(floor(1/time.last),'%05.3d'));
        end
        last_output_time=time.now;
    end
    hold off;
end
function [car_list]=draw_car(x,y,w,an1,an2,runtime,p,n,car,car_list,o)
    if (((o==0||runtime.before==0) && x.light.status==1 && x.light.change==true) || (x.light.status==2 && x.light.change==true))
        for i=1:car(1).num+car(2).num
            if (car_list(i).ignore==true && car_list(i).first==true)
                car_list(i).run=true;
                car_list(i).really_ignore=true;
                if (i+1<=n && car_list(i+1).line==car_list(i).line)
                    car_list(i+1).first=true;
                    car_list(i).first=false;
                end
            else
                car_list(i).run=false;
            end
        end
    end
    if (x.light.status==3 && x.light.change==true)
        for i=1:car(1).num+car(2).num
            car_list(i).run=true;
        end
    end
    
    if (((o==0||runtime.before==0) && y.light.status==1 && y.light.change==true) || (y.light.status==2 && y.light.change==true))
        for i=car(1).num+car(2).num+1:n
            if (car_list(i).ignore==true && car_list(i).first==true)
                car_list(i).run=true;
                car_list(i).really_ignore=true;
                disp(car_list(i).name);
                if (i+1<=n && car_list(i+1).line==car_list(i).line)
                    car_list(i+1).first=true;
                    car_list(i).first=false;
                end
            else
                car_list(i).run=false;
            end
        end
    end
    if (y.light.status==3 && y.light.change==true)
        for i=car(1).num+car(2).num+1:n
            car_list(i).run=true;
        end
    end
    % car will run after passing light even orange light
    for i=1:n
        if (car_list(i).line==1 && car_list(i).x>-w/2-3)
            car_list(i).run=true;
        end
        if (car_list(i).line==2 && car_list(i).x<w/2+3)
            car_list(i).run=true;
        end
        if (car_list(i).line==3 && car_list(i).y<w/2+3)
            car_list(i).run=true;
        end
        if (car_list(i).line==4 && car_list(i).y>-w/2-3)
            car_list(i).run=true;
        end
    end
    
    for i=1:n
        if (car_list(i).run==true) %|| car_list(i).
            if (car_list(i).line==1)
                car_list(i).x=car_list(i).x+runtime.last*10;
            end
            if (car_list(i).line==2)
                car_list(i).x=car_list(i).x-runtime.last*10;
            end
            if (car_list(i).line==3)
                car_list(i).y=car_list(i).y-runtime.last*10;
            end
            if (car_list(i).line==4)
                car_list(i).y=car_list(i).y+runtime.last*10;
            end
        end
        if (runtime.before==0)
            hold on;
            if (car_list(i).line<=2)
                car_list(i).draw=rectangle('Position',[car_list(i).x-3 car_list(i).y+2 6 4],'FaceColor','r');
            end
            if (car_list(i).line>=3)
                car_list(i).draw=rectangle('Position',[car_list(i).x+2 car_list(i).y-3 4 6],'FaceColor','r');
            end
            hold off;
        else
            if (car_list(i).line<=2)
                car_list(i).draw.Position=[car_list(i).x-3 car_list(i).y+2 6 4];
            end
            if (car_list(i).line>=3)
                car_list(i).draw.Position=[car_list(i).x+2 car_list(i).y-3 4 6];
            end
        end
        drawnow;
    end
end
function go(r,o,g,w,p,n,car,car_list)
    %for i=1:n
    %    disp([car_list(i).x,car_list(i).y])
    %end
    %to test
    [time,x,y]=start();
    draw_crossroad(w);
    an1 = animatedline;
    an2 = animatedline;
    runtime.before=0;
    runtime.now=0;
    tic;
    while true %to be updated in milestone 2, checking car
        runtime.before=runtime.now;
        runtime.now=toc;
        runtime.last=runtime.now-runtime.before;
        [x]=checklight(runtime.last,x,r,o,g);
        [y]=checklight(runtime.last,y,r,o,g);
        draw_light(x,y,w,an1,an2,runtime);
        [car_list]=draw_car(x,y,w,an1,an2,runtime,p,n,car,car_list,o);
        x.light.change=false;
        y.light.change=false;
        drawnow;
    end
end