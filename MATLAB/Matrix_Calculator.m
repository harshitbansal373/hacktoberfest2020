fprintf(" CALCULATOR\n");
fprintf("1 = Addition\n2 = Subtraction\n3 = Multiplication\n4 = Element wise multiplication\n5 = Element wise division\n6 = Element wise power operations");
X = input("\nEnter the operation: ");
if(X==3)
    n1 = input("Enter the number of rows of first matrix ");
    n2 = input("Enter the number of columns of first matrix ");
    p=n1*n2;
    disp('Input element of matrix column by column');
    for i = 1:p
        P(i) = input(['Enter element ' num2str(i) ': ']);
    end 
    A = reshape(P, n1, n2);
    n3 = input("Enter the number of rows of second matrix ");
    n4 = input("Enter the number of columns of second matrix ");
    q=n3*n4;
    disp('Input element of matrix column by column');
    for i = 1:q
        Q(i) = input(['Enter element ' num2str(i) ': ']);
    end 
    B = reshape(Q, n3, n4);
    if (n2~=n3)
        fprintf("Incorrect dimensions for matrix multiplication.");
        X=0;
    end
else    
    n1 = input("Enter the number of rows ");
    n2 = input("Enter the number of columns ");
    n=n1*n2;
    disp('Input element of the first matrix column by column');
    for i = 1:n
        A(i) = input(['Enter element ' num2str(i) ': ']);
    end
    disp('Input element of the second matrix column by column');
    for i = 1:n
        B(i) = input(['Enter element ' num2str(i) ': ']);
    end
end

switch (X)
    case 1
        for i= 1:n
            s(i) =A(i)+B(i);
        end    
    case 2 
        for i= 1:n
            s(i) =A(i)-B(i);
        end
    case 3
        M=zeros(n1,n4);
        for i= 1:n1 
            for j= 1:n4
                for k= 1:n2
                    M(i,j)= M(i,j)+A(i,k)*B(k,j);
                end
            end
        end 
        disp("Result is ");
        disp(M);
    case 4
        for i= 1:n
            s(i) =A(i)*B(i);
        end
    case 5
        for i= 1:n
            s(i) =A(i)/B(i);
        end
    case 6
        for i= 1:n
            s(i) =A(i)^B(i);
        end       
end
if(X~=3)
    S = reshape(s,n1,n2);
    disp("Result is");
    disp(S);
end
