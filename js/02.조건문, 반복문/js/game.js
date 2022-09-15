var low = 0;
        var high = 0;
        var card = 0; // 정답
        
        // 게임의 정답을 맞추기 위해서 무한로프를 돌고 있다.
        while(true){
            var tryCnt = 0;
            low = 0;
            high = 99;
            card = Math.floor(Math.random()*100);
            alert("수를 결정하였습니다. 맞춰 보세요");
            
            // 내부 루프는 정해진 난수를 맞출때까지 실행하는 것.
            while(true){
                var num = 0;
                alert(low + " ~ " + high);
                ++tryCnt;
                alert("시도 횟수 : " + tryCnt + "번째");
                
                num = window.prompt("숫자를 입력하세요!");
                num = parseInt(num);

                if(num > high || num < low){
                    alert("값의 범위를 벗어났습니다.");
                }else {
                    if(num == card){
                        alert("정답입니다. 짝짝짝!");
                        break;
                    }else if(num > card){
                        alert("다운!");
                        high = num;
                    }else{
                        alert("업!");
                        low = num;
                    }
                }
            }
            alert("시도횟수는 " + tryCnt + "입니다.");
            
            var con = confirm("다시 게임을 하시겠습니까?");
            // 무한루프를 사용할 경우에는 반드시 빠져나갈 곳을 만들어 두어야 한다.
            if(con == false){
                break;
            }
        }