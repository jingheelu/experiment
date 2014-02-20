#CME
xterm -title "CME" -fg "white" -bg "blue" -fs 10 -geometry 80x15+1396+0 -fn fixed -e "tail -f /var/log/debesys/cme.log" &
sleep 1
#CME send/recv
xterm -title "CME Send/Recv" -fg "white" -bg "darkblue" -fs 10 -geometry 80x15+1396+235 -fn fixed -e "tail -f /var/log/debesys/W73004_CME_send_recv.log" &
sleep 1
#Trader
xterm -title "T_TRADER" -fg "white" -bg "maroon" -fs 10 -geometry 80x15+1396+470 -fn fixed -e "tail -f /var/log/debesys/trader-`date +%Y`-`date +%m`-`date +%d`.log" &
sleep 1
#Trader Audit
xterm -title "T_TRADER Audit" -fg "white" -bg "darkgreen" -fs 10 -geometry 80x15+1396+705 -fn fixed -e "tail -f /var/log/debesys/audit-`date +%Y`-`date +%m`-`date +%d`.log" &
