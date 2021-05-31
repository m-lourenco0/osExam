#!/bin/bash
NASM=nasm/
MAIN=mainProgram/
# -- INICIA O PROGRAMA --
function start(){
    clear
    sleep 0.4
    cd $NASM
    ./intro
    cd ..
    sleep 0.4
    # -----------------------
    cd $MAIN
    ./prog
} 

function stop()
{
  matar=$(pidof -s prog)
  # -- VERIFICA SE O PROCESSO JA ESTA EM EXECUCAO --
  if [ $matar ]
  then
    # -- SE ESTIVER, MATA O PROCESSO --
    kill $matar
    return 1
  else
    # -- SE NAO ESTIVER, AVISA O USUARIO --
    sleep 0.3
    echo
    echo Processo ainda nao esta em execucao
    sleep 0.3
    return 0
  fi
}

function restart()
{
  stop
  # -- CASO O PROCESSO NAO ESTEJA EM EXECUCAO ANTES DE REINICIA-LO, FUNCAO AVISA USUARIO QUE ESTA INICIANDO --
  if [ $? -eq 0 ]
  then
    echo
    echo Iniciando...
    sleep 0.5
  fi
  sleep 1.2
  start
}

function usage()
{
  echo "-- -- -- -- -- -- -- -- --HELP-- -- -- -- -- -- -- -- -- --"
  echo "-- Para jogar utilize                | ./run.sh start    --"
  echo "-- Para parar a execucao utilize     | ./run.sh stop     --"
  echo "-- Para reiniciar o processo utilize | ./run.sh restart  --"
  echo "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --"
}

if [ $1 = "start" ]
then
  start
elif [ $1 = "stop" ]
then
  stop
elif [ $1 = "restart" ]
then
  restart
else
  usage
fi