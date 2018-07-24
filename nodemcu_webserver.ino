#include <ESP8266WiFi.h>
 
const char* ssid = "Mohan";
const char* password = "rekha123";
 
int ledPin = D5; 
int led2Pin = 5;
WiFiServer server(80);



void pic(){
                                                                              
Serial.println("                                    ```````");                                   
Serial.println("                             ```..........-------.`");
Serial.println("                         ``.....--..--------::://+/+/-`");                         
Serial.println("                       `.---..........------:::://+++o+:.");                       
Serial.println("                     .-----..........---------::///++oooo/.");                     
Serial.println("                   .---:---...........----------::/+++ossso:`");                   
Serial.println("                 `.-:::---...........-------:::::::+oossyyys+.");                  
Serial.println("                `.:::::---.......-...-----:::::::///+osyyyyso+-");                 
Serial.println("                .::::::---------------:::::::////+++osyyhhyysoo`");                
Serial.println("                -::::::::------:::::::///////////++ossyyhhhyyso:");                
Serial.println("               `-:::///::------::::///+++//::::://+oosyyyhhyyys/");                
Serial.println("               .://///::--:::::::://:/++//:://++///+o+osyhyyyyy+.");               
Serial.println("              `-:/++::--/+sossysssso/+++/::+osyyhyyyyyyssyhhhhyo:");               
Serial.println("              `::+++::shhhhhyyyhhhyso+oo++syhhhhhhhhhhhhhyhhhhys/");               
Serial.println("              `:/++/+hhhdhhhhhhhhhho+/::+yyddddddhhhhhysooshhhys/");               
Serial.println("              `:/oo:ohdhhhhhhhdhhhso/:::ohyddmmmmdhyso+////yyhys-");               
Serial.println("               -/o+:oyhhyysssyymmd++//-:+hhhdmmmdhhso+///:/hyhyo`");               
Serial.println("               `/o/-/yhhhyysossddo//::yhyhhhhhdmdhys+///:-+hyyy+");                
Serial.println("                :+:--/hhhhhhysoo+/-::shhyhhhhysyyssoo++/-:shyyy:");                
Serial.println("               `--::--:+syyyso+:--:-odhhhhhhys+///o+os+//syhhso-");                
Serial.println("               `::--::::/::///:::::/yhdddhhoyso++oossooosyyhhys:");                
Serial.println("                ./:---/+/+ooo+/+/::yshdhddsoyyooysoso+ooosyhhy+");                 
Serial.println("                 ./:-:///+++/++//:+hhmdydmhhsosysoo+++++oyhhy:");                  
Serial.println("                  ./ooossso///+/:::sddhohddsssyssoossyyhhhhs/");                   
Serial.println("                   -/o++yyyo::::::-::::/o+//oyyyysyhyyhddyy+`");                   
Serial.println("                    :s+/s//++:::/:-----://+++sysyyh+--hdhy+`");                    
Serial.println("                     .:/+o -+:::/::-:://::o/+/sshhh: ohhs-");                      
Serial.println("                      -/:s:./://::/-/:/+//o/o/syyhy./hhho");                       
Serial.println("                      .::+o:----./-.:`-/.-+-/::o++/+hhhy/");                       
Serial.println("                      `::-/::---.:---.-:.-+-+++o+++yyyyy-");                       
Serial.println("                      `::-:---::.-.:-:::://o/+oosyhysyys-");                       
Serial.println("                      `//---:::::::/-+:+:o///ossyysoyhyy:");                       
Serial.println("                       -/---::-:////////++++osyyssssyyho`");                       
Serial.println("                        -/--::/-:///:::/+++ossssyhyyhyo`");                        
Serial.println("                         .::-:::---:---/++++oo+syhyhy/`");                         
Serial.println("                           .-///:-----:/++/:/+shhho-");                    
Serial.println("                              .:++///+oso+++oshy/`");                      
Serial.println("                                 `.-///::///:-`");                         


}


 
void setup() {
  Serial.begin(115200);
  delay(10);
  pic();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  pinMode(led2Pin, OUTPUT);
  digitalWrite(led2Pin, LOW);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
int value = LOW;
int value2 = LOW;
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 

  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
  if (request.indexOf("/LED2=ON") != -1)  {
    digitalWrite(led2Pin, HIGH);
    value2 = HIGH;
  }
  if (request.indexOf("/LED2=OFF") != -1)  {
    digitalWrite(led2Pin, LOW);
    value2 = LOW;
  }
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led1 pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  

   client.print("Led2 pin is now: ");
 
  if(value2 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED2=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}

