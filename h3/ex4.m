function ex4()
    n=input('');
    printf_file=fopen("ex4_output.txt",'w');
    for i=0:10
        fprintf(printf_file,'%d x %d = %d\n',n,i,n*i);
    end
    fclose(printf_file);
end