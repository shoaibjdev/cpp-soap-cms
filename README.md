Apache DumpIO config
---
LoadModule dumpio_module modules/mod_dumpio.so
LogLevel dumpio:trace7
DumpIOInput On
DumpIOOutput On

gSOAP Compile and Execution
---

#### Generate SOAP
soapcpp2 -j hello.h
c++ -o publisher hello.cpp soapC.cpp soapService.cpp /home/skhan/softwares/gsoap-2.8/gsoap/stdsoap2.cpp


#### From Existing WSDL
wsdl2h [options] -o file.h ... WSDL and XSD files or URLs to WSDLs and XSDs ...
soapcpp2 [options] file.h


CMS Compile and Excecute
---

To compile
gcc publisher.cpp -o publisher -I/usr/local/include/activemq-cpp-3.9.4/ -I/usr/include/apr-1/ -lactivemq-cpp -lstdc++

To execute
./publisher


Final Working gSOAP + CMS
---
c++ -o publisher hello.cpp soapC.cpp soapService.cpp /home/skhan/softwares/gsoap-2.8/gsoap/stdsoap2.cpp publisher.cpp -I/usr/local/include/activemq-cpp-3.9.4/ -I/usr/include/apr-1/ -lactivemq-cpp -lstdc++ 

