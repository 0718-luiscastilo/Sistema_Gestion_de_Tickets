#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
class Persona{
  private:
    int id;
    std::string nombre;
    std::string correo;
    int telefono;
  
  public:
    Persona(int idPersona, std::string nombrePersona, std::string correoPersona, int telefonoPersona){
      id = idPersona;
      nombre = nombrePersona;
      correo = correoPersona;
      telefono = telefonoPersona;
    }
    void establecerId(int idPersona){
      id = idPersona;
    }
    void establecerNombre(std::string nombrePersona){
      nombre = nombrePersona;
    }
    void establecerCorreo(std::string  correoPersona){
    correo = correoPersona;
    }
    void establecerTelefono(int telefonoPersona){
      telefono = telefonoPersona;
    }
    int obtenerId() const{ 
      return id;
    }
    std::string obtenerNombre() const{
      return nombre;
    }
    std::string obtenerCorreo() const{
      return correo;
    }
    int obtenerTelefono()const {
      return telefono;
    }

    void mostrarInformacion() const{
      std::cout << "------------------------" << std::endl;
      std::cout << "ID: " << id << std::endl;
      std::cout << "Nombre  : " << nombre << std::endl;
      std::cout << "Correo: " << correo << std::endl;
      std::cout << "Telefono: " << telefono << std::endl;
    }

};
class Cliente : public Persona {
  private:
    std::string empresa;
    std::string tipoCliente;
    std::string estado; 
  public:
    Cliente(
    int idPersona,
    std::string nombrePersona,
    std::string correoPersona,
    int telefonoPersona,
    std::string clienteEmpresa,
    std::string clienteTipoCliente,
    std::string clienteEstado
    )
    : Persona(idPersona, nombrePersona, correoPersona, telefonoPersona),
    empresa(clienteEmpresa),
    tipoCliente(clienteTipoCliente),
    estado(clienteEstado)
    {
      
    }
    void establecerEmpresa(std::string clienteEmpresa){
      empresa = clienteEmpresa;
    }
    void establecerTipoCliente(std::string clienteTipoCliente){
      tipoCliente = clienteTipoCliente;
    }
    void establecerEstado(std::string clienteEstado){
      estado = clienteEstado;
    }
    std::string obtenerEmpresa() const{
      return empresa;
    }
    std::string obtenerTipoCliente() const{
      return tipoCliente;
    }
    std::string obtenerEstado() const{
      return estado;
    }

    void mostrarInformacion() const{
       std::cout << "ID: " << obtenerId() << std::endl;
       std::cout << "Nombre: " << obtenerNombre() << std::endl;
       std::cout << "Correo: " << obtenerCorreo() << std::endl;
       std::cout << "Telefono: " << obtenerTelefono() << std::endl;
       std::cout << "Empresa: " << empresa << std::endl;
       std::cout << "Tipo Cliente: " << tipoCliente << std::endl;
       std::cout << "Estado: " << estado << std::endl;
    }
    
};
class Ticket{
  private:
    int id;
    std::string descripcion;
    std::string prioridad;
    std::string estado;
    Cliente cliente;

  public:
    Ticket(int idTicket, std::string descripcionTicket, std::string prioridadTicket, std::string estadoTicket, Cliente clienteTicket) : cliente(clienteTicket){
      id = idTicket;
      descripcion = descripcionTicket;
      prioridad = prioridadTicket;
      estado = estadoTicket;
    }
    void establecerId(int idTicket){
      id = idTicket;
    }
    void establecerDescripcion(std::string descripcionTicket){
      descripcion = descripcionTicket;
    }
    void establecerPrioridad(std::string prioridadTicket){
      prioridad = prioridadTicket;
      }
      void establecerEstado(std::string estadoTicket){
        estado = estadoTicket;
      }

    int obtenerId() const{ 
      return id;
    }
    std::string obtenerDescripcion() const{
      return descripcion;
    }
    std::string obtenerPrioridad() const{
      return prioridad;
    }
    std::string obtenerEstado()const {
      return estado;
    }
    Cliente obtenerCliente()const {
      return cliente; 
    }
    void establecerCliente(Cliente clienteTicket){
      cliente = clienteTicket;
    }

    void mostrarInformacion() const{
      std::cout << "------------------------" << std::endl;
      std::cout << "ID: " << id << std::endl;
      std::cout << "Descripcion: " << descripcion << std::endl;
      std::cout << "Prioridad: " << prioridad << std::endl;
      std::cout << "Estado: " << estado << std::endl;
      std::cout << "--- Cliente Asociado ---" << std::endl;
      std::cout << "Nombre: " << cliente.obtenerNombre() << std::endl;
      std::cout << "Empresa: " << cliente.obtenerEmpresa() << std::endl;
      std::cout << "Tipo: " << cliente.obtenerTipoCliente() << std::endl;
    }

};
void mostrarClientesDisponibles(const std::vector<Cliente>& clientes){
  if(clientes.empty()){
    std::cout<<"No hay clientes registrados.\n";
    return;
    }
    std::cout << "\n=== CLIENTES DISPONIBLES ===\n";
    for(int i = 0; i < clientes.size(); i++){
      std::cout << i + 1 << ". " << clientes  [i].obtenerNombre() << " - " << clientes[i].obtenerEmpresa()  << std::endl;
    }

    std::cout << "===========================\n";
}  
void registrarTicket(std::vector<Ticket>& tickets, std::vector<Cliente>& clientes){
  int registroId;
  int opcionCliente;

  std::string registroDescripcion, registroPrioridad, registroEstado;

  std::cout << "ID: ";
  while(!(std::cin >> registroId)){
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::cout<<"Ingrese un número válido: ";
  }
  for(const Ticket& ticket : tickets){
    if(ticket.obtenerId() == registroId){
      std::cout << "Ese ID ya existe.\n";
      return;
    }
  }
  std::cout << "Descripcion: ";
  std::cin.ignore();
  std::getline(std::cin, registroDescripcion);
  std::cout << "Prioridad: ";
  std::cin >> registroPrioridad;
  std::cout << "Estado: ";
  std::cin >> registroEstado;

  mostrarClientesDisponibles(clientes);
  
  std::cout << "Seleccione un cliente: ";
  std::cin >> opcionCliente;
  while(opcionCliente < 1 || opcionCliente > static_cast<int>(clientes.size())){
    std::cout << "Cliente invalido. Intente nuevamente: ";
    std::cin >> opcionCliente;
}
Cliente clienteSeleccionado = clientes[opcionCliente - 1];


Ticket nuevoTicket(registroId, registroDescripcion, registroPrioridad, registroEstado, clienteSeleccionado);

tickets.push_back(nuevoTicket);
std::cout << "\nTicket registrado correctamente.\n";

}
int mostrarMenu(){
    int opcion;

    std::cout << "Bienvenido" << std::endl;
    std::cout << "1.- Registrar nuevo ticket" << std::endl;
    std::cout << "2.- Mostrar todos los tickets" << std::endl;
    std::cout << "3.- Buscar ticket por ID" << std::endl;
    std::cout << "4.- Cambiar estado de un ticket" << std::endl;
    std::cout << "5.- Mostrar tickets abiertos" << std::endl;
    std::cout << "6.- Mostrar tickets cerrados" << std::endl;
    std::cout << "7.- Mostrar estadísticas generales" << std::endl;
    std::cout << "8.- Guardar tickets en archivo" << std::endl;
    std::cout << "9.- Cargar tickets desde archivo" << std::endl;
    std::cout << "10.- Salir" << std::endl;

    std::cout << "Escoge una opcion: ";
    std::cin >> opcion;

    return opcion;
}
void mostrarTodosLosTickets(const std::vector<Ticket>& tickets){
    if(tickets.empty()){
        std::cout << "No hay tickets registrados.\n";
        return;
    }

    for(const Ticket& ticket : tickets){
        ticket.mostrarInformacion();
        std::cout << std::endl;
    }
}
void buscarTicketPorId(const std::vector<Ticket>& tickets){
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  int idBuscado;
  bool encontrado = false;
  std::cout << "Ingrese ID del ticket: ";
  std::cin >> idBuscado;

  for(const Ticket& ticket : tickets){
    if(ticket.obtenerId() == idBuscado){
      encontrado = true;
      ticket.mostrarInformacion();
    }
  }
  if(!encontrado){
      std::cout << "Ticket no encontrado.\n";
  } 
}
void cambiarEstadoTicket(std::vector<Ticket>& tickets){
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  int idBuscado;
  bool encontrado = false;

  std::cout << "Ingrese ID del ticket: ";
  std::cin >> idBuscado;
  for(Ticket& ticket : tickets){
    if(ticket.obtenerId() == idBuscado){
      encontrado = true;
      std::cout << "\n=== TICKET ENCONTRADO ===\n";
      ticket.mostrarInformacion();
      std::cout << "\nEstado actual: " << ticket.obtenerEstado() << std::endl;
      int opcionEstado;
      do{
        std::cout << "\nSeleccione el nuevo estado:\n";
        std::cout << "1. Abierto\n";
        std::cout << "2. EnProceso\n";
        std::cout << "3. Cerrado\n";
        std::cout << "Opcion: ";
        std::cin >> opcionEstado;
        switch(opcionEstado){
          case 1:
            ticket.establecerEstado("Abierto");
            break;
          case 2:
            ticket.establecerEstado("EnProceso");
            break;
          case 3:
            ticket.establecerEstado("Cerrado");
            break;
            default:
              std::cout << "Opcion invalida.\n";
          }
      }while(opcionEstado < 1 || opcionEstado > 3);
      std::cout << "\nEstado actualizado correctamente.\n";
      std::cout << "\n=== TICKET ACTUALIZADO ===\n";
      ticket.mostrarInformacion();
      break;
    }
  }
  if(!encontrado){
    std::cout << "Ticket no encontrado.\n";
  }
}
void mostrarAbiertos(std::vector<Ticket>& tickets){
  bool estaAbierto = false;
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  for(Ticket& ticket : tickets){
    if(ticket.obtenerEstado() == "Abierto"){
      estaAbierto = true;
      ticket.mostrarInformacion();
    }
  }
  if(!estaAbierto){
    std::cout << "No hay tickets Abiertos";
  }
}
void mostrarCerrados(std::vector<Ticket>& tickets){
  bool existeCerrado = false;
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  for(Ticket& ticket : tickets){
    if(ticket.obtenerEstado() == "Cerrado"){
      existeCerrado = true;
      ticket.mostrarInformacion();
    }
  }
  if(!existeCerrado){
    std::cout << "No hay tickets Cerrados.\n";
  }
}
void mostrarEstadisticas(const std::vector<Ticket>& tickets){
  int abiertos = 0;
  int cerrados = 0;
  int enProceso = 0;
  int alta = 0;
  int media = 0;
  int baja = 0;
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  int totalTickets = static_cast<int>(tickets.size());
  for(const Ticket& ticket : tickets){

    // Estados
    if(ticket.obtenerEstado() == "Abierto"){
        abiertos++;
    }
    else if(ticket.obtenerEstado() == "Cerrado"){
        cerrados++;
    }
    else if(ticket.obtenerEstado() == "EnProceso"){
        enProceso++;
    }

    // Prioridades
    if(ticket.obtenerPrioridad() == "Alta"){
        alta++;
    }
    else if(ticket.obtenerPrioridad() == "Media"){
        media++;
    }
    else if(ticket.obtenerPrioridad() == "Baja"){
        baja++;
    }
  }
  std::cout << "\n===== ESTADISTICAS =====\n"<< std::endl;
  std::cout << "Total Tickets: "<< totalTickets << std::endl;
  std::cout << "\n--- Estados ---\n";
  std::cout << "Abiertos: "<< abiertos << std::endl;
  std::cout << "En Proceso: "<< enProceso << std::endl;
  std::cout << "Cerrados: "<< cerrados << std::endl;
  std::cout << "\n--- Prioridades ---\n";
  std::cout << "Prioridad Alta: "<< alta << std::endl;
  std::cout << "Prioridad Media: "<< media << std::endl;
  std::cout << "Prioridad Baja: "<< baja << std::endl;

  double porcentajeAbiertos = (abiertos * 100.0) / totalTickets;
  double porcentajeCerrados = (cerrados * 100.0) / totalTickets;
  double porcentajeProceso = (enProceso * 100.0) / totalTickets;

  std::cout << "\n--- Porcentajes ---\n";
  std::cout << "Abiertos: " << porcentajeAbiertos << "%\n";
  std::cout << "En Proceso: " << porcentajeProceso << "%\n";
  std::cout << "Cerrados: " << porcentajeCerrados << "%\n";
}
void guardarTickets(const std::vector<Ticket>& tickets){
  if(tickets.empty()){
    std::cout << "No hay tickets registrados.\n";
    return;
  }
  std::ofstream archivo("tickets.txt");
  if(!archivo){
    std::cout << "Error al abrir archivo.\n";
    return;
  }
  for(const Ticket& ticket : tickets){
    archivo
        << ticket.obtenerId() << ";"
        << ticket.obtenerDescripcion() << ";"
        << ticket.obtenerPrioridad() << ";"
        << ticket.obtenerEstado() << ";"
        << ticket.obtenerCliente().obtenerId()
        << std::endl;
  }
  if(archivo.fail()){
    std::cout<<"Error al guardar.\n";
  }else{
    std::cout<<"Tickets guardados correctamente.\n";
  }
}
void cargarTickets(std::vector<Ticket>& tickets, const std::vector<Cliente>& clientes){
  if(clientes.empty()){
    std::cout << "No hay clientes registrados.\n";
    return;
  }
  std::ifstream archivo("tickets.txt");
  if(!archivo){
    std::cout << "No se pudo abrir el archivo.\n";
    return;
  }
  
  if(archivo.peek() == EOF){
    std::cout << "El archivo está vacío.\n";
    return;
  }
  tickets.clear();
  std::string linea;
  while(std::getline(archivo, linea)){
    std::string idTexto;
    std::string descripcion;
    std::string prioridad;
    std::string estado;
    std::string idClienteTexto;

    std::stringstream ss(linea);

    std::getline(ss, idTexto, ';');
    std::getline(ss, descripcion, ';');
    std::getline(ss, prioridad, ';');
    std::getline(ss, estado, ';');
    std::getline(ss, idClienteTexto);
    
    if(idTexto.empty() || idClienteTexto.empty()){
      std::cout << "Línea inválida.\n";
      continue;
    }
    int id = std::stoi(idTexto);
    int idCliente = std::stoi(idClienteTexto);
    
    bool clienteExiste = false;
    Cliente clienteEncontrado = clientes[0];

    for(const Cliente& cliente : clientes){
      if(cliente.obtenerId() == idCliente){
        clienteEncontrado = cliente;
        clienteExiste = true; 
        break;
      }
    }
    if(!clienteExiste){
      std::cout << "Cliente con ID " << idCliente << " no encontrado.\n";
      continue;
    }

    Ticket nuevoTicket(id, descripcion, prioridad, estado,clienteEncontrado);
    tickets.push_back(nuevoTicket);
  }
  archivo.close();
  std::cout << "\nTickets cargados correctamente.\n";
  std::cout << "Total de tickets cargados: " << tickets.size() << std::endl;
}

int main() {
  int opcion;  
  std::vector<Ticket> tickets;
  std::vector<Cliente> clientes;
  Cliente cliente1(1, "Francisco", "correo@ejemplo.com", 123456789, "OpenAI", "VIP", "Activo");
  Cliente cliente2(2, "Ana", "ana@correo.com", 987654321, "Microsoft", "Regular", "Activo");
  clientes.push_back(cliente1);
  clientes.push_back(cliente2);

  do{
    opcion = mostrarMenu();
    switch(opcion){
      case 1:
      registrarTicket(tickets, clientes);
      break;
      case 2:
      mostrarTodosLosTickets(tickets);
      break;
      case 3:
      buscarTicketPorId(tickets);
      break;
      case 4:
      std::cout << "Cambiar estado de un ticket" << std::endl;
      cambiarEstadoTicket(tickets);
      break;
      case 5:
      mostrarAbiertos(tickets);
      break;
      case 6:
      mostrarCerrados(tickets);
      break;
      case 7:
      mostrarEstadisticas(tickets);
      break;
      case 8:
      guardarTickets(tickets);
      break;
      case 9:
      cargarTickets(tickets, clientes);
      break;
      case 10:
      std::cout << "Saliendo..." << std::endl;
      break;
      default:
      std::cout << "Opcion invalida" << std::endl;
    }
  }while(opcion != 10);
  return 0;
}