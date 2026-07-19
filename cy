mkdir -p ~/company/{Finance,HR,Engineering}
echo "Payroll Data" > ~/company/Finance/payroll.txt
echo "Employee Records" > ~/company/HR/employees.txt
echo "Source Code" > ~/company/Engineering/app.py
find ~/company -type f -exec mv "{}" "{}.locked" \;
tar -czf ~/archives/ex_data.tar.gz ~/company

nc -l -p 12345
sudo snort -A console -q -u snort -g snort -c /etc/snort/snort.conf -i enp0s3
