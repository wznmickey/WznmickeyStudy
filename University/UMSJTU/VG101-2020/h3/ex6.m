function ex6()
    n=input('');
    file=fopen('ex6_output.txt','w');
    Ans=zeros(n);
    Ans(1,1)=1;
    for i=2:n
        Ans(1,i)=1;
        for j=2:i
           Ans(j,i)=Ans(j-1,i-1)+Ans(j,i-1);
        end
    end
    for i=1:n
        for j=(i+1):n
            fprintf(file,'   ');
        end
        for j=1:i
            fprintf(file,'%6d',Ans(j,i));
        end
        fprintf(file,'\n');
    end
    fclose('all');
end