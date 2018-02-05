//
//  PageViewController.swift
//  Offers
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class PageViewController: UIViewController {

    let pageViewController = UIPageViewController(transitionStyle: .scroll, navigationOrientation: .horizontal, options: nil)
    var viewControllers: [UIViewController]? = nil
    var viewTitles: [String]? = nil

    override func viewDidLoad() {
        super.viewDidLoad()

        viewControllers = [ (storyboard?.instantiateViewController(withIdentifier: "MyOffers"))!, (storyboard?.instantiateViewController(withIdentifier: "RewardsStore"))! ]
        viewTitles = [ "My Rewards", "Rewards Store" ];
        
        var tag = 0;
        viewControllers?.forEach({ (controller) in
            controller.view.tag = tag;
            tag = tag + 1;
        })

        let pageControl = UIPageControl.appearance()
        pageControl.pageIndicatorTintColor = UIColor.red
        pageControl.currentPageIndicatorTintColor = UIColor.green
        pageControl.backgroundColor = UIColor.white

        pageViewController.dataSource = self;
        
        pageViewController.setViewControllers([ (viewControllers?.first!)! ], direction: .forward, animated: true) { (done) in }
        navigationController?.navigationBar.topItem!.title = viewTitles?.first!

        addChildViewController(pageViewController)
        view.addSubview(pageViewController.view)
    }

    @IBAction func doLogout(_ sender: Any) {
        dismiss(animated: true, completion: nil)
        SessionM.sharedInstance().logOutUser()
    }
}

extension PageViewController: UIPageViewControllerDataSource {
    public func pageViewController(_ pageViewController: UIPageViewController, viewControllerBefore viewController: UIViewController) -> UIViewController? {
        return transitionPage(index: viewController.view.tag - 1)
    }

    public func pageViewController(_ pageViewController: UIPageViewController, viewControllerAfter viewController: UIViewController) -> UIViewController? {
        return transitionPage(index: viewController.view.tag + 1)
    }

    private func transitionPage(index : Int) -> UIViewController? {
        let idx = abs(index) % (self.viewControllers?.count)!
        return self.viewControllers?[idx];
    }

    public func presentationCount(for pageViewController: UIPageViewController) -> Int {
        return viewControllers!.count;
    }

    public func presentationIndex(for pageViewController: UIPageViewController) -> Int {
        return 0;
    }
}

