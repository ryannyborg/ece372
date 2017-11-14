//
//  ViewController.swift
//  finalproject372
//
//  Created by Ryan Nyborg on 4/17/17.
//  Copyright © 2017 Ryan Nyborg. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var bleManager: BLEManagable?
    @IBOutlet weak var temperatureLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        bleManager?.addDelegate(self)
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        bleManager?.removeDelegate(self)
    }


}

// MARK: BLEManagerDelegate
extension ViewController: BLEManagerDelegate {
    
    func bleManagerDidConnect(_ manager: BLEManagable) {
        self.temperatureLabel.textColor = UIColor.black
    }
    func bleManagerDidDisconnect(_ manager: BLEManagable) {
        self.temperatureLabel.textColor = UIColor.red
    }
    func bleManager(_ manager: BLEManagable, receivedDataString dataString: String) {
        self.temperatureLabel.text = dataString + "ºF"
    }
}

