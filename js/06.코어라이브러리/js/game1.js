// 지구본을 클릭하면 점수가 1씩 올라감. 제한시간 5초.
var point = 0;
var $score = $("#score");
var $earth = $("#earth");
var play = true;    // 플래그 변수

$(document).ready(function(){
    
    $earth.on("click", function(){     // 클릭하면 콜백함수 실행
        if(play){
            point++;
            $score.html(point);
            moveEarth();
        }
    });
    // 5초 후 종료
    setTimeout(function(){
        play = false;
        alert("종료!!");;
    }, 5000);
});

function moveEarth() {
    var x = parseInt(Math.random()*550);
    var y = parseInt(Math.random()*450);

    $earth.css({
        left: x,
        top: y
    });
}

function init() {
    $earth = $("#earth");
    $score = $("#score");
    $timer = $("#timer");
    point = 0;
    timer = 5;
}