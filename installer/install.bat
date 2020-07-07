@echo off

pushd %~dp0

if exist "C:\Program Files (x86)\macchina\dpdpu" echo Driver folder already exists, ignoring
if not exist "C:\Program Files (x86)\macchina\dpdu" mkdir "C:\Program Files (x86)\macchina\dpdu"

if not exist "C:\ProgramData\D-PDU API" (
	echo Error. No D-PDU API Folder found!
	pause
	exit
)

echo "Copying files"
xcopy /s/y "pdu_api_root.xml" "C:\ProgramData\D-PDU API"
if errorlevel 1 (
	echo Error copying DPDPU XML file
	pause
	exit
)

xcopy /s/y "*_macchina_m2.xml" "C:\Program Files (x86)\macchina\dpdu"
if errorlevel 1 (
	echo Error copying DPDPU CDF/MDF XML file
	pause
	exit
)

echo Install complete!
pause