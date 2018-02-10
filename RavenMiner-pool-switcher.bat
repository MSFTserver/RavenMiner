rem || User Options!
set Pool=stratum+tcp://pool.threeeyed.info:3333
set User=Your-Address-Here
set ExtraOptions=Rig1,stats
set YourTime=3600
set DonationTime=3600
set DonationAddress=RT2r9oGxQxbVE1Ji5p5iPgrqpNQLfc8ksH
:Start
RavenMiner-x64.exe -o %Pool% -u %User% -p %ExtraOptions% --time-limit %YourTime%
ping localhost -n 2 >nul
RavenMiner-x64.exe -o %Pool% -u %DonationAddress% -p %ExtraOptions% --time-limit %DonationTime%
goto Start
@pause