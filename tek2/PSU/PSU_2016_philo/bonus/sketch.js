SCREEN_WIDTH = 1024;
List_PosX = 750;
List_PosY = 50;
Philos = [];
var lines;
var eatImg;
var sleepImg;
var thinkImg;
var idx = 1;

function preload() {
  lines = loadStrings("out.txt");
}

function setup() {

  eatImg = loadImage("rice.png");
  sleepImg = loadImage("bed.png");
  thinkImg = loadImage("brainstorm.png");

  slider = createSlider(0, 10, 1, 1);
  slider.position(SCREEN_WIDTH / 2 - 100, 300);
  slider.style('width', '200px');
  Nb_Philo = lines[0];

  for (i = 0; i < Nb_Philo ; i++) {

    Angle = (i / (Nb_Philo / 2)) * PI;

    Philos.push({
      ID : i + 1,
      Eat : 0,
      Rest : 0,
      Think : 0,
      State : -1,
      PosX : (150 * cos(Angle) + SCREEN_WIDTH / 2),
      PosY : (150 * sin(Angle) + SCREEN_WIDTH / 2)
    })
  }
  button = createButton('Restart');
  button.position(SCREEN_WIDTH / 2 - 40, SCREEN_WIDTH / 2);
  button.mousePressed(resetSimulation);
  createCanvas(1024, 1024);
}

function resetSimulation() {
  Philos.forEach(function(philo){
    philo.State = -1;
    philo.Eat = 0;
    philo.Think = 0;
    philo.Rest = 0;
  })
  idx = 1;
}

function drawLegend() {
  fill(50, 205, 50);
  rect(300, 800, 25, 25);
  text("Sleeping", 345, 820);
   fill(30, 144, 255);
  rect(500, 800, 25, 25);
  text("Thinking", 545, 820);
   fill(255, 99, 71);
  rect(700, 800, 25, 25);
  text("Eating", 745, 820);
}

function draw(){

  frameRate(slider.value());
  background(255);
  fill(255);
  ellipse(width / 2, height / 2, 250, 250);

  if (slider.value() != 0 && lines[idx] != undefined)
  {
  philo = lines[idx].split(":")[0];
  action = lines[idx].split(":")[1];
  Philos[philo].State = action;
  if (action == 0)
    Philos[philo].Rest += 1;
  if (action == 1)
    Philos[philo].Think += 1;
  else if (action == 2)
    Philos[philo].Eat += 1;    
  idx += 1;
  }

  Philos.forEach(function(philo){
    if (philo.State == 0)
      fill(color(50, 205, 50));
    else if (philo.State == 1)
      fill(color(30, 144, 255));
    else if (philo.State == 2)
      fill(color(255, 99, 71));
    else
      fill(255);
    ellipse(philo.PosX, philo.PosY, 45, 45);
    fill(0);
    textSize(20);
    text(philo.ID, philo.PosX - 6, philo.PosY + 6);

    textStyle(BOLD);
    text("Speed management", (width / 2) - 110, 280);
    text("Philosophers", List_PosX + 70, List_PosY + 30);
    text(philo.ID, List_PosX, 100 + List_PosY + philo.ID * 50);

    image(eatImg, 50 + List_PosX, 50 + List_PosY, eatImg.width / 10, eatImg.height / 10)
    image(sleepImg, 50 + List_PosX + 75, 50 + List_PosY, sleepImg.width / 10, sleepImg.height / 10)
    image(thinkImg, 50 + List_PosX + 150, 50 + List_PosY, thinkImg.width / 10, thinkImg.height / 10)

    textStyle(NORMAL);
    text(philo.Eat, List_PosX + 72, 100 + List_PosY + philo.ID * 50);
    text(philo.Rest, List_PosX + 144, 100 + List_PosY + philo.ID * 50);
    text(philo.Think, List_PosX + 218, 100 + List_PosY + philo.ID * 50);
  })
  drawLegend();
}