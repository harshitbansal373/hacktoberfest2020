function output = nand(A,B)
n=length(A);
output=zeros(1,n);
for i=1:n
    if(A(i)==1 && B(i)==1)
        output(i)=0;
    elseif(A(i)==1)
        output(i)=1;
    elseif(B(i)==1)
        output(i)=1;
    else
        output(i)=1;
    end
end