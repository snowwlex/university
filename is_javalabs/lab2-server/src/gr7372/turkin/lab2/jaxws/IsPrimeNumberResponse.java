
package gr7372.turkin.lab2.jaxws;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

@XmlRootElement(name = "isPrimeNumberResponse", namespace = "http://lab2.turkin.gr7372/")
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "isPrimeNumberResponse", namespace = "http://lab2.turkin.gr7372/")
public class IsPrimeNumberResponse {

    @XmlElement(name = "return", namespace = "")
    private boolean _return;

    /**
     * 
     * @return
     *     returns boolean
     */
    public boolean isReturn() {
        return this._return;
    }

    /**
     * 
     * @param _return
     *     the value for the _return property
     */
    public void setReturn(boolean _return) {
        this._return = _return;
    }

}
