function ex3()
    load mandrill
    figure
    image(X)
    colormap(map)
    axis off
    imwrite(X,map,'ans_mandrill.png')
    Y=imread('ans_mandrill.png');
    pause(2)% wait for another picture;
    image(Y)
end