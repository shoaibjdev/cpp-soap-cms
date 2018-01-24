#include "ns.nsmap"  // include the generated source code headers
#include "soapService.h" // include XML namespaces
#include "publisher.h"

using namespace std;

int main()
{
      Service serv(SOAP_XML_INDENT);
      if(serv.serve() != SOAP_OK)
          serv.soap_stream_fault(std::cerr);
      serv.destroy();
}
int Service::hello(double input, double &out)
{
    out = 0; 
    //cout << "Staring to invoke CMS API..." << endl;
    CMSPublisher cms_pub;
    std::string final_response = cms_pub.send_to_queue("Some data to be sent to queue");
    //cout << "Response from Queue: " << final_response << endl;
    return SOAP_OK;
}
