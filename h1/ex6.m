data=input('');
type=input('','s');
if (strcmp('stones to pounds',type)) % char array can be checked whether they "=="  only when they have the same length (num of elements in the array) 
    fans=14.*data;
elseif (strcmp(type,'pounds to kg'))
    fans=(6.35/14).*data;
else fans=data/6.35;
end
disp(fans);