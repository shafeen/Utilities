var randomScalingFactor = function(){ return Math.round(Math.random()*100)};

function testBarChart(canvasId) {
    var barChartData = {
        labels: ["January", "February", "March", "April", "May", "June", "July"],
        datasets: [
            {
                fillColor: "rgba(220,220,220,0.5)",
                strokeColor: "rgba(220,220,220,0.8)",
                highlightFill: "rgba(220,220,220,0.75)",
                highlightStroke: "rgba(220,220,220,1)",
                data: [randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor()]
            },
            {
                fillColor: "rgba(151,187,205,0.5)",
                strokeColor: "rgba(151,187,205,0.8)",
                highlightFill: "rgba(151,187,205,0.75)",
                highlightStroke: "rgba(151,187,205,1)",
                data: [randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor(), randomScalingFactor()]
            }
        ]
    };

    var ctx = document.getElementById(canvasId).getContext("2d");
    var myBar = new Chart(ctx).Bar(barChartData, {
        responsive: true
    });

    // update data with random datasets every 2 seconds
    setInterval(function () {
        myBar.datasets.forEach(function (dataset) {
            dataset.bars.forEach(function (bar) {
                bar.value = randomScalingFactor();
            });
        });
        myBar.update();
    }, 2000);

}
window.onload = function () {
    testBarChart("barChartCanvas");
};
