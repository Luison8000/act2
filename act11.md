```bash
public class Triangulo {
    // ATRIBUTOS
    private float Base, Altura;
    private String Tipo; 
    // METODOS
    // Constructor
    public Triangulo(float B, float A) {
        // Inicializar base y altura
        this.Base=B;
        this.Altura=A;
    }
    public void setTipo (String T) {
        this.Tipo=T;    
    }
    public void setBase (float B) {   
        this.Base=B;
    } 
    public void setAltura (float A) {    
        this.Altura=A;
    }
    public String getTipo () {    
        return this.Tipo;
    }
    public float getBase (){    
        return this.Base;
    }
    public float getAltura (){   
        return this.Altura;
    }
    // Métodos adicionales
    public float calculaArea (){
        // Calcular el área
        return this.Base*this.Altura/2;
    }
}

------------------------------------------------------

public static void main(String[] args) {
        
        // Declarar variables
        float BaseT, AlturaT;
        
        // Pedir datos
        Scanner sc = new Scanner(System.in);
        System.out.println("Base: ");
        BaseT=sc.nextFloat();
        System.out.println("Altura: ");
        AlturaT=sc.nextFloat();
                        
        // Crear objeto
        Triangulo T1=new Triangulo(BaseT, AlturaT);
        
        // Asignar tipo
        System.out.println("Tipo del triángulo: ");
        T1.setTipo(sc.nextLine());
                
        // Mostrar datos
        System.out.println("Tipo: "+T1.getTipo());
        System.out.println("Base: "+T1.getBase());
        System.out.println("Altura: "+T1.getAltura());
        System.out.println("Area: "+T1.calculaArea());
                       
    }
--------------------------------------------------------------

 public static void muestraDatosTriangulo(Triangulo triDatos) {
        
        // Método que muestra datos del triangulo
        System.out.println("Tipo: "+triDatos.getTipo());
        System.out.println("Base: "+triDatos.getBase());
        System.out.println("Altura: "+triDatos.getAltura());
        System.out.println("Area: "+triDatos.calculaArea());
        
    } 
-----------------------------------------------------------------

// Crear objeto
  Triangulo pruebaTriangulo=new Triangulo(BaseT, AlturaT); 
  muestraDatosTriangulo(pruebaTriangulo);

-----------------------------------------------------------------
public class JavaApplication2 {

    public static void mostrarSaludo() {
            
        String nombre;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Cual es tu nombre? ");
        nombre=sc.nextLine();
        
        System.out.println("Hola "+nombre);
    }
    
    public static void main(String[] args) {
        
        // Invocar método estático
        MostrarSaludo();
        
    }
    
}
```
-----------------------------------------------------

