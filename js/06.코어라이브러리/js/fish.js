var $fish = null;
        var step = 50;
        var timerID = 0;

        $(document).ready(function(){
            init();
            initEvent();
        })

        function init() {
            $fish = $("#fish");
        }
        function initEvent() {
            $("#btnStart").on("click", function(){
                start();
            });
            $("#btnStop").on("click", function(){
                stop();
            });

        }
        // 물고기 움직이기 타이머 실행
        function start() {
            if(timerID == 0) {
                timerID = setInterval(function(){
                    moveFish();
                }, 100);
            }
        }
        // 물고기 멈추기 
        function stop() {
            alert(timerID);
            clearInterval(timerID);
            timerID = 0;
        }

        // 물고기 움직이기
        function moveFish() {
            var x = $fish.position().left + step;   // 다음 물고기의 위치
            
            // 물고기 이동 방향을 바꿔주는 부분
            if(x >= 430){
                $fish.attr("src", "images/fish2.png");    // .attr()함수는 선택자에 의해 선택된 요소들 중 요소의 속성값을 반환하는 함수.
                step = -50;
            }
            if(x < 50){
                $fish.attr("src", "images/fish1.png");    // .attr()함수는 선택자에 의해 선택된 요소들 중 요소의 속성값을 반환하는 함수.
                step = 50;
            }
            $fish.css("left", x);  
        }