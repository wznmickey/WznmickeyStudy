[x,y]=Ex2_step1();
[x,y]=Ex2_step2(x,y);
[x,y]=Ex2_step3(x,y);
[x,y]=Ex2_step4(x,y);
[x,y,z]=Ex2_step5(x,y);
[x,y,z,w]=Ex2_step6(z);
[x,y]=Ex2_step7(x,y,w);
function [x,y]=Ex2_init()
    x=[3;2;6;8];
    y=[4;1;3;5];
end
function [x,y]=Ex2_step1()    
    [x,y]=Ex2_init();
    disp(x)
    disp(y)
    Ex2_init();% Because specifications 2, after question 1, there still be a reset.
end
function [x,y]=Ex2_step2(x,y)
    y(5)= sum(x);
    disp(x);
    disp(y);
    [x,y]=Ex2_init();
end
function [x,y]=Ex2_step3(x,y)
    x=x.^y;
    disp(x);
    disp(y);
    [x,y]=Ex2_init();
end
function [x,y]=Ex2_step4(x,y)
    y=x.\y;
    disp(y);
    disp(x);
    [x,y]=Ex2_init();
end
function [x,y,z]=Ex2_step5(x,y)     
    z=x.*y;
    disp(x);
    disp(y);
    disp(z);
    [x,y]=Ex2_init();
end
function [x,y,z,w]=Ex2_step6(z)
    w=sum(z);
    disp(z);
    disp(w);
    [x,y]=Ex2_init();% Because specifications 2, even there is no chagnge of x and y, there still be a reset.
end
function [x,y]=Ex2_step7(x,y,w)
    disp(x);
    disp(y);
    disp(w);
    disp(x'*y-w);
    [x,y]=Ex2_init();% because specifications 2
    % The result comes from the action that firstly, multiplies the nonconjugate transpose of x and
    % y by multiplying corresponding elements and then minus w.
end