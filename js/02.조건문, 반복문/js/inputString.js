var intputString = null;
        
        alert("메시지를 입력하세요");
        alert("프로그램을 종료하려면 q를 입력하세요.");

        // 최소 한번은 무조건 실행된다. 사용자의 의도를 물어보는 프로그램에 사용하면 좋다.
        do{
            inputString = window.prompt("메시지를 입력하세요");
            if(inputString != "q")
                document.write(inputString + "<br>");
        }while(!(inputString=="q"));

        document.write("프로그램 종료!!");