# Project 1

### How to use

**RUN main.m**

**PLEASE obey the instructions**, or something wrong will happen.

You will be asked to input several numbers,after that one crossroad will appear with lights.
Several cars will appear based on your input.
If cars cross the road successfully, you will win, or you will lose.

### Features
 - ***flexible FPS***
 - show FPS in the screen
 - check whether inputs of light time may lead to accidents
 - change the color based on the iuput
 - assign cars into 4 lines
 - print the crossroad
 - draw cars
 - check whether there is an accident
 - ***bonus***
    1. cars with different size and color 
    2. difficulty level provided

### Bugs

 - The figure window may reopen or go wrong if the user close it before the end of the animation.
 - It may go wrong after input if the user doesn't obey the instructions.

### Algorithm

|name|meaning|
|---|---|
|x|info in x axis|
|y|info in y axis|
|w|width of road|
|n|num of cars|
|car|num of cars in different lines|
|car_list| info of car|
|o|time of orange light|
|r|time of red light|
|g|time of green light|
|runtime|the time|
|p|the possibility a car will ignore color|

#### the motion of the cars

reason: Dividing the motion of cars by light color makes it easier to calculate the location of cars

- input: x,y,w,runtime,n,car,car_list,o
- output: animation,plates of cars which didn't stop

```
function [car_list,run_flag,draw_flag]=draw_car(x,y,w,runtime,n,car,car_list,o)
    run_flag←true;
    draw_flag←false;
    [car_list]←check_stop(o,runtime,x,1,car(1).num+car(2).num,car_list);
    [car_list]←check_stop(o,runtime,y,car(1).num+car(2).num+1,n,car_list);
    % car will run after passing light even orange light
    for i=1 to n
        if (car_list(i).line==1 && car_list(i).x>-w/2-3)
            car_list(i).run←true;
            if (i+1<=n && car_list(i+1).line==car_list(i).line)
                car_list(i+1).first←true;
                car_list(i).first←false;
            end
        end
        if (car_list(i).line==2 && car_list(i).x<w/2+3)
            car_list(i).run←true;
            if (i+1<=n && car_list(i+1).line==car_list(i).line)
                car_list(i+1).first←true;
                car_list(i).first←false;
            end
        end
        if (car_list(i).line==3 && car_list(i).y<w/2+3)
            car_list(i).run←true;
            if (i+1<=n && car_list(i+1).line==car_list(i).line)
                car_list(i+1).first←true;
                car_list(i).first←false;
            end
        end
        if (car_list(i).line==4 && car_list(i).y>-w/2-3)
            car_list(i).run←true;
            if (i+1<=n && car_list(i+1).line==car_list(i).line)
                car_list(i+1).first←true;
                car_list(i).first←false;
            end
        end
    end
    for i=1 to n
        if (car_list(i).run==true)
            if (car_list(i).line==1)
                car_list(i).x←car_list(i).x+runtime.last*10;
            end
            if (car_list(i).line==2)
                car_list(i).x←car_list(i).x-runtime.last*10;
            end
            if (car_list(i).line==3)
                car_list(i).y←car_list(i).y-runtime.last*10;
            end
            if (car_list(i).line==4)
                car_list(i).y←car_list(i).y+runtime.last*10;
            end
        end
        if (abs(car_list(i).x)<=50 && abs(car_list(i).y)<=50 && car_list(i).isdraw==false)
            draw car_list(i);
        end
    end
    [run_flag]=checkcrash(car_list,n,w);
end

function [car_list]=check_stop(o,runtime,x,car_start,car_end,car_list)
    if (((o==0||runtime.before==0) && x.light.status==1 && x.light.change==true) || (x.light.status==2 && x.light.change==true))
        for i=car_start to car_end
            if (car_list(i).ignore==true && car_list(i).first==true)
                car_list(i).run←true;
                car_list(i).really_ignore←true;
                print "NOT STOP: " + car_list(i).name;
                if (i+1<=car_end && car_list(i+1).line==car_list(i).line)
                    car_list(i+1).first←true;
                    car_list(i).first←false;
                end
            else
                car_list(i).run←false;
            end
        end
    end
    if (x.light.status==3 && x.light.change==true)
        for i=car_start to car_end
            car_list(i).run←true;
        end
    end
end

function[run_flag]=checkcrash(car_list,n,w)
    run_flag←true;
    risk_car1←[car_list(1)];
    l_risk_car1←0;
    risk_car2←[car_list(1)];
    l_risk_car2←0;
    for i=1 to n
        if ((abs(car_list(i).x)<=w) && (abs(car_list(i).y)<=w))
            if car_list(i).line<=2
                risk_car1(1,l_risk_car1+1)←car_list(i);
                l_risk_car1←l_risk_car1+1;
            end
            if car_list(i).line>=3
                risk_car2(1,l_risk_car2+1)←car_list(i);
                l_risk_car2←l_risk_car2+1;
            end
        end
    end
    for i=1 to l_risk_car1
        for j=1 to l_risk_car2
            if (abs(risk_car1(1,i).x-risk_car2(1,j).x)<=5 && abs(risk_car1(1,i).y-risk_car2(1,j).y)<=5)
                run_flag←false;
                return;
            end
        end
    end
end
```

#### the change of color of the traffic lights

reason: Calculating and store light in x and y indenpendently makes it easier to check the color

- input: r,o,g,w
- output: animataion
```
function go(r,o,g,w)
    [time,x,y]←start();
    runtime.before←0;
    runtime.now←0;
    tic;
    while (true)
        runtime.before←runtime.now;
        runtime.now←toc;
        runtime.last←runtime.now-runtime.before;
        [x]←checklight(runtime.last,x,r,o,g);
        [y]←checklight(runtime.last,y,r,o,g);
        draw_light(x,y,w);
        x.light.change←false;
        y.light.change←false;
    end
end

function [time,x,y]=start()
    time←0;
    x.light.status←3;% 1-r,2-o,3-g
    x.light.time←0;
    y.light.status←1;
    y.light.time←0;
    x.light.change←true;
    y.light.change←true;
end

function [x]=checklight(time,x,r,o,g)
    x.light.time←x.light.time+time;
    if (x.light.status==2 && x.light.time>=o)
        x.light.status←1;
        x.light.time←x.light.time-o;
        x.light.change←true;
    end
    if (x.light.status==1 && x.light.time>=r)
        x.light.status←3;
        x.light.time←x.light.time-r;
        x.light.change←true;
    end
    if (x.light.status==3 && x.light.time>=g)
        x.light.status←2;
        x.light.time←x.light.time-g;
        x.light.change←true;
        if (o==0)
            x.light.status←1;
        end
    end
end

function draw_light(x,y,w)
    w←w/2;
    if x.light.change==true
        draw x.light.status in w,w;
        draw x.light.status in -w,-w;
    end
    if y.light.change==true
        draw y.light.status in w,-w;
        draw y.light.status in -w,w;
    end
end
```

#### permutations

- input: A,l
- output: B

```
function [B]←generate_permutations(A,l) %A is the set and l is the length
    temp_l←SizeOf(A);
    if l==1
        for i=1 to temp_l
            LET A(i) be the i^th line of B;
        end
    else
        temp_set←generate_permutations(A,l-1);
        temp_size←size(temp_set,1);
        temp_i←0;
        for i=1 to temp_l
            for j=1 to temp_size
                temp_i←temp_i+1;
                ADD A(i) at the end of j^th line of temp_set;
                temp_i^th line of B ← j^th line of temp_set;
            end
        end
    end
end

function [a,b]←swap(a,b)
    temp←a;
    a←b;
    b←temp;
end
```
#### adjusted_permutations

- input: A,l,num
- output: B

```
function [B]←generate_permutations_adjusted(A,l,num)%A is the set and l is the length
    persistent temp_l;
    temp_l←numel(A);
    if l==1
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        for i=temp_l downto 2
            j←randi(i);
            [A(i),A(j)]←swap(A(i),A(j));
        end
        for i=1 to num
            i^th line of B ← A(i);
        end
    else
        %get num random number
        % reference: The Art of Computer Programming Vol 2: Seminumercial
        % Algorithms
        temp_max←power(temp_l,l);
        temp_A=1 to temp_max;
        for j=1 to num
            k←randi(temp_max-j+1)+j-1;
            [temp_A(k),temp_A(j)]←swap(temp_A(k),temp_A(j));
        end
        DELETE temp_A from (num+1)^th line to end;
        temp_A←floor((temp_A-1)./power(temp_l,l-1))+1;
        temp_B←a temp_l*1 array filled with 0;
        for i=1 to num
            temp_B(temp_A(i))←temp_B(temp_A(i))+1;
        end
        temp_i←0;
        for i = 1 to temp_l
            if (temp_B(i)>0)
                temp_set←generate_permutations_adjusted(A,l-1,temp_B(i));
                for j = 1 to temp_B(i)
                    temp_i←temp_i+1;
                    ADD A(i) at the end of j^th line of temp_set;
                    temp_i^th line of B ← j^th line of temp_set;
                end
            end
        end
    end
end
```