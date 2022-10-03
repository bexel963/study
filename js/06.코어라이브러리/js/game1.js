// 지구본을 클릭하면 점수가 1씩 올라감. 제한시간 5초.


$(document).ready(function(){

    var point = 0;
    var $score = $("#score");
    var $earth = $("#earth");
    var play = true;    // 플래그 변수
    var time = 5;

    init();
    $earth.on("click", function(){     // 클릭하면 콜백함수 실행
        if(play){
            point++;
            $score.html(point);
            moveEarth();
        }
    });
    var timerId = setInterval(function(){
        time--;
        $('#timer').html(time);
    }, 1000);
    // 5초 후 종료
    setTimeout(function(){
        clearInterval(timerId);
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














// $(document).ready(function(){
//     var $earth = $('#earth');
//     var $score = $('#score');
//     var $timer = $('#timer');
//     var x = 0;
//     var y = 0;
//     var point = 0;
//     var time = 5;
//     var timerId = null;            
//     var play = true;

//     timerId = setInterval(function(){        
        
//         if(time < 1){
//             alert('게임 종료!');
//             play = false;
//             clearInterval(timerId);
//         }else{
//             time--;
//             $timer.text(time);
//         }       
//     }, 1000);
    
//     $earth.on('click', function(){
//         if(play) {
//             x = Math.floor(Math.random() * 550);
//             y = Math.floor(Math.random() * 450);
            
//             $earth.css({
//                 'left' : x,
//                 'top' : y
//             });
//             point++;
//             $score.text(point);
//         }
//     })
// })