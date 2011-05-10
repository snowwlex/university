
package gr7372.turkin.lab2;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the gr7372.turkin.lab2 package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _ArithmeticSequenceResponse_QNAME = new QName("http://lab2.turkin.gr7372/", "arithmeticSequenceResponse");
    private final static QName _GeomSequenceResponse_QNAME = new QName("http://lab2.turkin.gr7372/", "geomSequenceResponse");
    private final static QName _ArithmeticSequence_QNAME = new QName("http://lab2.turkin.gr7372/", "arithmeticSequence");
    private final static QName _FibbonachiSequence_QNAME = new QName("http://lab2.turkin.gr7372/", "fibbonachiSequence");
    private final static QName _Factorial_QNAME = new QName("http://lab2.turkin.gr7372/", "factorial");
    private final static QName _FibbonachiSequenceResponse_QNAME = new QName("http://lab2.turkin.gr7372/", "fibbonachiSequenceResponse");
    private final static QName _IsPrimeNumber_QNAME = new QName("http://lab2.turkin.gr7372/", "isPrimeNumber");
    private final static QName _IsPrimeNumberResponse_QNAME = new QName("http://lab2.turkin.gr7372/", "isPrimeNumberResponse");
    private final static QName _FactorialResponse_QNAME = new QName("http://lab2.turkin.gr7372/", "factorialResponse");
    private final static QName _GeomSequence_QNAME = new QName("http://lab2.turkin.gr7372/", "geomSequence");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: gr7372.turkin.lab2
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link GeomSequence }
     * 
     */
    public GeomSequence createGeomSequence() {
        return new GeomSequence();
    }

    /**
     * Create an instance of {@link GeomSequenceResponse }
     * 
     */
    public GeomSequenceResponse createGeomSequenceResponse() {
        return new GeomSequenceResponse();
    }

    /**
     * Create an instance of {@link FibbonachiSequenceResponse }
     * 
     */
    public FibbonachiSequenceResponse createFibbonachiSequenceResponse() {
        return new FibbonachiSequenceResponse();
    }

    /**
     * Create an instance of {@link ArithmeticSequence }
     * 
     */
    public ArithmeticSequence createArithmeticSequence() {
        return new ArithmeticSequence();
    }

    /**
     * Create an instance of {@link IsPrimeNumberResponse }
     * 
     */
    public IsPrimeNumberResponse createIsPrimeNumberResponse() {
        return new IsPrimeNumberResponse();
    }

    /**
     * Create an instance of {@link ArithmeticSequenceResponse }
     * 
     */
    public ArithmeticSequenceResponse createArithmeticSequenceResponse() {
        return new ArithmeticSequenceResponse();
    }

    /**
     * Create an instance of {@link FibbonachiSequence }
     * 
     */
    public FibbonachiSequence createFibbonachiSequence() {
        return new FibbonachiSequence();
    }

    /**
     * Create an instance of {@link FactorialResponse }
     * 
     */
    public FactorialResponse createFactorialResponse() {
        return new FactorialResponse();
    }

    /**
     * Create an instance of {@link Factorial }
     * 
     */
    public Factorial createFactorial() {
        return new Factorial();
    }

    /**
     * Create an instance of {@link IsPrimeNumber }
     * 
     */
    public IsPrimeNumber createIsPrimeNumber() {
        return new IsPrimeNumber();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ArithmeticSequenceResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "arithmeticSequenceResponse")
    public JAXBElement<ArithmeticSequenceResponse> createArithmeticSequenceResponse(ArithmeticSequenceResponse value) {
        return new JAXBElement<ArithmeticSequenceResponse>(_ArithmeticSequenceResponse_QNAME, ArithmeticSequenceResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GeomSequenceResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "geomSequenceResponse")
    public JAXBElement<GeomSequenceResponse> createGeomSequenceResponse(GeomSequenceResponse value) {
        return new JAXBElement<GeomSequenceResponse>(_GeomSequenceResponse_QNAME, GeomSequenceResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link ArithmeticSequence }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "arithmeticSequence")
    public JAXBElement<ArithmeticSequence> createArithmeticSequence(ArithmeticSequence value) {
        return new JAXBElement<ArithmeticSequence>(_ArithmeticSequence_QNAME, ArithmeticSequence.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link FibbonachiSequence }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "fibbonachiSequence")
    public JAXBElement<FibbonachiSequence> createFibbonachiSequence(FibbonachiSequence value) {
        return new JAXBElement<FibbonachiSequence>(_FibbonachiSequence_QNAME, FibbonachiSequence.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link Factorial }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "factorial")
    public JAXBElement<Factorial> createFactorial(Factorial value) {
        return new JAXBElement<Factorial>(_Factorial_QNAME, Factorial.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link FibbonachiSequenceResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "fibbonachiSequenceResponse")
    public JAXBElement<FibbonachiSequenceResponse> createFibbonachiSequenceResponse(FibbonachiSequenceResponse value) {
        return new JAXBElement<FibbonachiSequenceResponse>(_FibbonachiSequenceResponse_QNAME, FibbonachiSequenceResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link IsPrimeNumber }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "isPrimeNumber")
    public JAXBElement<IsPrimeNumber> createIsPrimeNumber(IsPrimeNumber value) {
        return new JAXBElement<IsPrimeNumber>(_IsPrimeNumber_QNAME, IsPrimeNumber.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link IsPrimeNumberResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "isPrimeNumberResponse")
    public JAXBElement<IsPrimeNumberResponse> createIsPrimeNumberResponse(IsPrimeNumberResponse value) {
        return new JAXBElement<IsPrimeNumberResponse>(_IsPrimeNumberResponse_QNAME, IsPrimeNumberResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link FactorialResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "factorialResponse")
    public JAXBElement<FactorialResponse> createFactorialResponse(FactorialResponse value) {
        return new JAXBElement<FactorialResponse>(_FactorialResponse_QNAME, FactorialResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GeomSequence }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://lab2.turkin.gr7372/", name = "geomSequence")
    public JAXBElement<GeomSequence> createGeomSequence(GeomSequence value) {
        return new JAXBElement<GeomSequence>(_GeomSequence_QNAME, GeomSequence.class, null, value);
    }

}
